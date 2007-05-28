#ifndef OBJECTS_MD3_SURFACE_HPP
#define OBJECTS_MD3_SURFACE_HPP

#include <vector>

#include <boost/shared_ptr.hpp>

#include "md3_common.hpp"
#include "md3_shader.hpp"

/*
-            SURFACE_START Offset relative to start of MD3 object.
S32          IDENT         Magic number. As a string of 4 octets, reads "IDP3"; as unsigned little-endian 1367369843 (0x51806873); as unsigned big-endian 1936228433 (0x73688051).
U8*MAX_QPATH NAME          Name of Surface object. ASCII character string, NUL-terminated (C-style). Current value of MAX_QPATH is 64.
S32          FLAGS         ???
S32          NUM_FRAMES    Number of animation frames. This should match NUM_FRAMES in the MD3 header.
S32          NUM_SHADERS   Number of Shader objects defined in this Surface, with a limit of MD3_MAX_SHADERS. Current value of MD3_MAX_SHADERS is 256.
S32          NUM_VERTS     Number of Vertex objects defined in this Surface, up to MD3_MAX_VERTS. Current value of MD3_MAX_VERTS is 4096.
S32          NUM_TRIANGLES Number of Triangle objects defined in this Surface, maximum of MD3_MAX_TRIANGLES. Current value of MD3_MAX_TRIANGLES is 8192.
S32          OFS_TRIANGLES Relative offset from SURFACE_START where the list of Triangle objects starts.
S32          OFS_SHADERS   Relative offset from SURFACE_START where the list of Shader objects starts.
S32          OFS_ST        Relative offset from SURFACE_START where the list of St objects (Texture Coordinates, S-T vertices) starts.
S32          OFS_XYZNORMAL Relative offset from SURFACE_START where the list of Vertex objects (X-Y-Z-N vertices) starts.
S32          OFS_END       Relative offset from SURFACE_START to where the Surface object ends.
!            (Shader)      List of Shader objects usually starts immediate after the Surface header, but use OFS_SHADERS (or rather, OFS_SHADERS+OFS_SURFACES for files).
!            (Triangle)    List of Triangle objects usually starts immedately after the list of Shader objects, but use OFS_TRIANGLES (+ OFS_SURFACES).
!            (St)          List of St objects usually starts immedately after the list of Triangle objects, but use OFS_ST (+ OFS_SURFACES).
!            (XYZNormal)   List of Vertex objects usually starts immediate after the list of St objects, but use OFS_XYZNORMALS (+ OFS_SURFACES). The total number of objects is (NUM_FRAMES * NUM_VERTS). One set of NUM_VERTS Vertex objects describes the Surface in one frame of animation; the first NUM_VERTS Vertex objects describes the Surface in the first frame of animation, the second NUM_VERTEX Vertex objects describes the Surface in the second frame of animation, and so forth.
-            SURFACE_END   End of Surface object. Should match OFS_END.
*/

struct md3_surface_header
{
	int magic;
	char name[MD3_MAX_NAME];
	int flags;
	int frame_count;
	int shader_count;
	int vertex_count;
	int triangle_count;
	int triangle_offset;
	int shader_offset;
	int st_offset;
	int xyzn_offset;
	int end_offset;
};

/*
S16 X      X-coordinate in left-handed 3-space, scaled down by factor MD3_XYZ_SCALE. Current value of MD3_XYZ_SCALE is (1.0/64). (multiply by MD3_XYZ_SCALE to obtain original coordinate value)
S16 Y      Y-coordinate in left-handed 3-space, scaled down by factor MD3_XYZ_SCALE. Current value of MD3_XYZ_SCALE is (1.0/64). (multiply by MD3_XYZ_SCALE to obtain original coordinate value)
S16 Z      Z-coordinate in left-handed 3-space, scaled down by factor MD3_XYZ_SCALE. Current value of MD3_XYZ_SCALE is (1.0/64). (multiply by MD3_XYZ_SCALE to obtain original coordinate value)
S16 NORMAL Encoded normal vector. See Normals.
*/

struct md3_xyzn
{
	short int x;
	short int y;
	short int z;
	short int n;
};

/*
F32*2 ST S-T (U-V?) texture coordinate. I am a little fuzzy on the whole notion of texture coordinates. Values tend to stay within [0.0 .. 1.0], suggesting (0,0) is one corner of the shader/texture and (1,1) is the other far corner of the shader/texture, with values outside the range indicating wraparounds/repeats. Again, I am fuzzy on this notion.
*/

struct md3_st
{
	float s;
	float t;
};

/*
S32*3 INDEXES List of offset values into the list of Vertex objects that constitute the corners of the Triangle object. Vertex numbers are used instead of actual coordinates, as the coordinates are implicit in the Vertex object. (XXX: does order matter?)
*/

struct md3_triangle
{
	int a;
	int b;
	int c;
};

class texture_wrapper;

class md3_surface
{
public:
	void read(std::istream& input);
	
	int frame_count() const;

	void draw_frame(int frame) const;

private:
	md3_surface_header header;
	
	std::vector<md3_shader> shaders;
	std::vector<md3_xyzn> xyzns;
	std::vector<md3_st> sts;
	std::vector<md3_triangle> triangles;

	std::vector<md3_vector> vertices;
	std::vector<md3_vector> normals;

	boost::shared_ptr<texture_wrapper> texture;
};

#endif //OBJECTS_MD3_SURFACE_HPP
