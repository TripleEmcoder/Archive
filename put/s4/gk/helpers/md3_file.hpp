#ifndef HELPERS_MD3_FILE_HPP
#define HELPERS_MD3_FILE_HPP

#include <vector>

#include <boost/shared_ptr.hpp>

#include "md3_common.hpp"
#include "md3_frame.hpp"
#include "md3_surface.hpp"

/*
-            MD3_START    Offset of MD3 object. Usually 0, but not guaranteed.
S32          IDENT        Magic number. As a string of 4 octets, reads "IDP3"; as unsigned little-endian 1367369843 (0x51806873); as unsigned big-endian 1936228433 (0x73688051).
S32          VERSION      MD3 version number, latest known is 15, but use the constant MD3_VERSION.
U8*MAX_QPATH NAME         MD3 name, usually its pathname in the PK3. ASCII character string, NUL-terminated (C-style). Current value of MAX_QPATH is 64.
S32          FLAGS        ???
S32          NUM_FRAMES   Number of Frame objects, with a maximum of MD3_MAX_FRAMES. Current value of MD3_MAX_FRAMES is 1024.
S32          NUM_TAGS     Number of Tag objects, with a maximum of MD3_MAX_TAGS. Current value of MD3_MAX_TAGS is 16.
S32          NUM_SURFACES Number of Surface objects, with a maximum of MD3_MAX_SURFACES. Current value of MD3_MAX_SURFACES is 32.
S32          NUM_SKINS    Number of Skin objects. I should note that I have not seen an MD3 using this particular field for anything; this appears to be an artifact from the Quake 2 MD2 format. Surface objects have their own Shader field.
S32          OFS_FRAMES   Relative offset from start of MD3 object where Frame objects start. The Frame objects are written sequentially, that is, when you read one Frame object, you do not need to seek() for the next object.
S32          OFS_TAGS     Relative offset from start of MD3 where Tag objects start. Similarly written sequentially.
S32          OFS_SURFACES Relative offset from start of MD3 where Surface objects start. Again, written sequentially.
S32          OFS_EOF      Relative offset from start of MD3 to the end of the MD3 object. Note there is no offset for Skin objects.
!            (Frame)      The array of Frame objects usually starts immediately afterwards, but OFS_FRAMES should be used.
!            (Tag)        The array of Tag objects usually starts immediately after FRAMES, but OFS_TAGS should be used.
!            (Surface)    The array of Surface objects usually start after TAGS, but OFS_SURFACES should be used.
-            MD3_END      End of MD3 object. Should match MD3_START.
*/

struct md3_file_header
{
	int magic;
	int version;
	char name[MD3_MAX_NAME];
	int flags;
	int frame_count;
	int tag_count;
	int surface_count;
	int skin_count;
	int frame_offset;
	int tag_offset;
	int surface_offset;
	int eof_offset;
};

class list_wrapper;

class md3_file
{
public:
	md3_file(std::istream& input);
	void read(std::istream& input);
	
	int frame_count() const;

	void draw_frame(int frame) const;

private:
	md3_file_header header;

	std::vector<md3_frame> frames;
	std::vector<md3_surface> surfaces;

	std::vector<boost::shared_ptr<list_wrapper> > lists;
};

#endif //HELPERS_MD3_FILE_HPP
