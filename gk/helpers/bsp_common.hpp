#ifndef HELPERS_BSP_COMMON_HPP
#define HELPERS_BSP_COMMON_HPP

const float BSP_SCALE = 1.0f / 33.33f;

struct bsp_vector3i
{
	int x, y, z;
};

struct bsp_vector2f
{
	float x, y;
};

struct bsp_vector3f
{
	bsp_vector3f(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) { };
	float x, y, z;
};

struct bsp_header
{
	char id[4];
	int version;
};

struct bsp_lump
{
	int offset;
	int length;
};

struct bsp_vertex
{
	bsp_vector3f position;
	bsp_vector2f texture_coordinate;
	bsp_vector2f lightmap_coordinate;
	bsp_vector3f normal;
	unsigned char color[4];
};

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
	bsp_vector3f lightmap_origin;
	bsp_vector3f lightmap_vectors[2];
	bsp_vector3f normal;
	int size[2];
};

struct bsp_texture
{
	char name[64];
	int flags;
	int contents;
};

struct bsp_lightmap
{
	unsigned char pixels[128][128][3];
};

struct bsp_plane
{
	bsp_vector3f normal;
	float distance;
};

struct bsp_node
{
	int plane;
	int front;
	int back;
	bsp_vector3i mins;
	bsp_vector3i maxs;
};

struct bsp_leaf
{
	int cluster; 				//Visdata cluster index. 
	int area; 					//Areaportal area. 
	bsp_vector3i mins;
	bsp_vector3i maxs;
	int start_leafface_index; 	//First leafface for leaf. 
	int leaffaces_count;		//Number of leaffaces for leaf. 
	int start_leafbrush_index; 	//First leafbrush for leaf. 
	int leafbrushes_count;		//Number of leafbrushes for leaf.
};

struct bsp_visdata
{
	int vecs_count;
	int vecs_size;
	unsigned char* vecs;
};

struct bsp_model
{
	bsp_vector3i mins;
	bsp_vector3i maxs;
	int start_face_index; 		//First face for model. 
	int face_count; 			//Number of faces for model. 
	int start_brush_index;		//First brush for model. 
	int brush_count; 			//Number of brushes for model.
};

template <typename T> void swizzle(T& v)
{
	std::swap(v.y, v.z);
	v.z *= -1;
}

template <typename T> void scale(T& v, float scale)
{
	v.x *= scale;
	v.y *= scale;
	v.z *= scale;
}

#endif //HELPERS_BSP_COMMON_HPP
