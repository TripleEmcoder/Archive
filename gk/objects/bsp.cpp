#include "bsp.hpp"
#include "scope.hpp"
#include "engine.hpp"

//type TVector3i = Record
//	X, Y, Z : Integer;
//end;

struct bsp_vector3i
{
	int x, y, z;
};

//type TVector2f = Record
//	X, Y : glFloat;
//end;

struct bsp_vector2f
{
	float x, y;
};

//type TVector3f = Record
//	X, Y, Z : glFloat;
//end;

struct bsp_vector3f
{
	float x, y, z;
};

//type TBSPHeader = Record
//	strID : Array[0..3] of Char;           // This should always be 'IBSP'
//	Version : Integer;                     // This should be 0x2e for Quake 3 files
//end;

struct bsp_header
{
	char id[4];
	int version;
};

//type TBSPLump = Record
//	Offset : Integer;                      // The offset into the file for the start of this lump
//	Length : Integer;                      // The length in bytes for this lump
//end;

struct bsp_lump
{
	int offset;
	int length;
};

//type TBSPVertex = Record
//	Position      : TVector3f;             // (x, y, z) position.
//	TextureCoord  : TVector2f;             // (u, v) texture coordinate
//	LightmapCoord : TVector2f;             // (u, v) lightmap coordinate
//	Normal        : TVector3f;             // (x, y, z) normal vector
//	Color         : Array[0..3] of Byte    // RGBA color for the vertex
//end;

struct bsp_vertex
{
	bsp_vector3f position;
	bsp_vector2f texture_coordinate;
	bsp_vector2f lightmap_coordinate;
	bsp_vector3f normal;
	char color[4];
};

//type TBSPFace = Record
//	textureID : Integer;                   // The index into the texture array
//	effect    : Integer;                   // The index for the effects (or -1 = n/a)
//	FaceType  : Integer;                   // 1=polygon, 2=patch, 3=mesh, 4=billboard
//	startVertIndex : Integer;              // The starting index into this face's first vertex
//	numOfVerts     : Integer;              // The number of vertices for this face
//	meshVertIndex  : Integer;              // The index into the first meshvertex
//	numMeshVerts   : Integer;              // The number of mesh vertices
//	lightmapID     : Integer;              // The texture index for the lightmap
//	lMapCorner : Array[0..1] of Integer;   // The face's lightmap corner in the image
//	lMapSize   : Array[0..1] of Integer;   // The size of the lightmap section
//	lMapPos  : TVector3f;                  // The 3D origin of lightmap.
//	lMapVecs : Array[0..1] of TVector3f;   // The 3D space for s and t unit vectors.
//	vNormal  : TVector3f;                  // The face normal.
//	Size : Array[0..1] of Integer;         // The bezier patch dimensions. 
//end;

struct bsp_face
{
	int texture_index;
	int effect_index;
	int face_type;
	int start_vertex_index;
	int vertex_count;
	int start_mesh_vertex_index;
	int mesh_vertex_count;
	int lightmap_index;
	int lightmap_corner[2];
	int lightmap_size[2];
	bsp_vector3f lightmap_origin[2];
	bsp_vector3f lightmap_vectors[2];
	bsp_vector3f normal;
	int size[2];
};

//type TBSPTexture = Record
//	TextureName : Array[0..63] of Char;    // The name of the texture w/o the extension
//	flags    : Integer;                    // The surface flags (unknown)
//	contents : Integer;                    // The content flags (unknown)
//end;

struct bsp_texture
{
	char name[64];
	int flags;
	int contents;
};

//type TBSPLightmap = Record
//	imageBits : Array[0..127, 0..127, 0..2] of Byte;   // The RGB data in a 128x128 image
//end;

struct bsp_lightmap
{
	char pixels[128][128][3];
};

void bsp::compile(const object& parent)
{
	object::compile(parent);
	
	//wczytywanie

/*
{-----------------------------------------------------------}
{---  This loads in all of the .bsp data for the level   ---}
{-----------------------------------------------------------}
function TQuake3BSP.LoadBSP(const FileName: String): Boolean;
var F : File;
    I : Integer;
    Temp : glFloat;
    Header : TBSPHeader;
    Lumps  : Array of TBSPLump;
    BSPTextures  : Array of TBSPTexture;
begin
  result :=FALSE;

  // Check if the .bsp file can be opened
  AssignFile(F, filename);
{$I-}
  Reset(F,1);
{$I+}
  if IOResult <> 0 then
  begin
    MessageBox(0, 'Could not find the BSP file!', 'Error', MB_OK);
    exit;
  end;

  SetLength(Lumps, kMaxLumps);

  // Read in the header and lump data
  BlockRead(F, Header, Sizeof(Header));
  BlockRead(F, Lumps[0], kMaxLumps*sizeof(TBSPLump));

  // Allocate the vertex memory
  numOfVerts := Round(lumps[kVertices].length / sizeof(TBSPVertex));
  SetLength(Vertices, numOfVerts);

  // Allocate the face memory
  numOfFaces := Round(lumps[kFaces].length / sizeof(TBSPFace));
  SetLength(Faces, numOfFaces);

  // Allocate memory to read in the texture information.
  numOfTextures := Round(lumps[kTextures].length / sizeof(TBSPTexture));
  SetLength(BSPTextures, numOfTextures);
  SetLength(Textures, numOfTextures);

  // Seek to the position in the file that stores the vertex information
  Seek(F, lumps[kVertices].offset);

  // Go through all of the vertices that need to be read and swap axises
  for I :=0 to numOfVerts-1 do
  begin
    // Read in the current vertex
    BlockRead(F, Vertices[i], sizeOf(TBSPVertex));

    // Swap the y and z values, and negate the new z so Y is up.
    Temp := Vertices[i].Position.Y;
    Vertices[i].Position.Y := Vertices[i].Position.Z;
    Vertices[i].Position.Z := -temp;

    // Negate the V texture coordinate because it is upside down otherwise...
    Vertices[i].TextureCoord.Y := -Vertices[i].TextureCoord.Y;
  end;

  // Seek and read in all the face information
  Seek(F, lumps[kFaces].offset);
  BlockRead(F, Faces[0], numOfFaces*sizeOf(TBSPFace));

  // Seek and read in all the texture information
  Seek(F, lumps[kTextures].offset);
  BlockRead(F, BSPTextures[0], numOfTextures*sizeOf(TBSPTexture));

  // Go through all of the textures
  for I :=0 to numOfTextures-1 do
  begin
    // for some reason known only to ID they dont store file extentions
    if FileExists(BSPTextures[i].TextureName + '.jpg') then
      LoadTexture(BSPTextures[i].TextureName + '.jpg', Textures[i], FALSE)
    else if FileExists(BSPTextures[i].TextureName + '.tga') then
      LoadTexture(BSPTextures[i].TextureName + '.tga', Textures[i], FALSE)
  end;
  CloseFile(F);

  result :=TRUE;
end;
*/
}

void bsp::draw() const
{
	scope local(composition());

	//rysowanie

/*
{-----------------------------------------------------------}
{--- Renders a face, determined by the passed in index   ---}
{-----------------------------------------------------------}
procedure TQuake3BSP.RenderFace(faceIndex: Integer);
var Face : TBSPFace;
begin
  // Here we grab the face from the index passed in
  Face := Faces[faceIndex];

  glEnable(GL_TEXTURE_2D);                // Turn on texture mapping and bind the face's texture map
  glBindTexture(GL_TEXTURE_2D, textures[Face.textureID]);

  // Draw the face in a triangle face, starting from the starting index
  // to the starting index + the number of vertices.  This is a vertex array function.
  glDrawArrays(GL_TRIANGLE_FAN, Face.startVertIndex, Face.numOfVerts);
end;


{---------------------------------------------------------------------}
{--- Goes through all faces and draws them if type is FACE_POLYGON ---}
{---------------------------------------------------------------------}
procedure TQuake3BSP.RenderLevel(const Pos: TVector3f);
var i : Integer;
begin
  // Give OpenGL our vertices to use for vertex arrays
  glVertexPointer(3, GL_FLOAT, sizeof(TBSPVertex), @Vertices[0].Position);

  // Since we are using vertex arrays, we need to tell OpenGL which texture
  // coordinates to use for each texture pass.  We switch our current texture
  // to the first one, then set our texture coordinates.
  glTexCoordPointer(2, GL_FLOAT, sizeof(TBSPVertex), @Vertices[0].TextureCoord);

  // Set our vertex array client states for vertices and texture coordinates
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);

  // Get the number of faces in our level and go through all the faces
  i := numOfFaces;
  while i > 0 do
  begin
    Dec(I);

    // Before drawing this face, make sure it's a normal polygon
    if Faces[i].Facetype = FACE_POLYGON then
      RenderFace(i);
  end;
end;
*/
}
