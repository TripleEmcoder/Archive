#include "bezier.hpp"
#include "opengl.hpp"

bsp_vertex operator*(const bsp_vertex& v, const float x)
{
	bsp_vertex result(v);

	result.position.x *= x;
	result.position.y *= x;
	result.position.z *= x;

	result.texture_coordinate.x *= x;
	result.texture_coordinate.y *= x;

	result.normal.x *= x;
	result.normal.y *= x;
	result.normal.z *= x;

	result.lightmap_coordinate.x *= x;
	result.lightmap_coordinate.y *= x;

	result.color[0] *= x;
	result.color[1] *= x;
	result.color[2] *= x;
	result.color[3] *= x;
	return result;
}

bsp_vector2f operator+(const bsp_vector2f& l, const bsp_vector2f& r)
{
	bsp_vector2f result;
	result.x = l.x + r.x;
	result.y = l.y + r.y;
	return result;
}

bsp_vector3f operator+(const bsp_vector3f& l, const bsp_vector3f& r)
{
	bsp_vector3f result;
	result.x = l.x + r.x;
	result.y = l.y + r.y;
	result.z = l.z + r.z;
	return result;
}

bsp_vertex operator+(const bsp_vertex& l, const bsp_vertex& r)
{
	bsp_vertex result;

	result.position = l.position + r.position;
	result.normal = l.normal + r.normal;
	result.texture_coordinate = l.texture_coordinate + r.texture_coordinate;
	result.lightmap_coordinate = l.lightmap_coordinate + r.lightmap_coordinate;

	result.color[0] = l.color[0] + r.color[0];
	result.color[1] = l.color[1] + r.color[1];
	result.color[2] = l.color[2] + r.color[2];
	result.color[3] = l.color[3] + r.color[3];

	return result;
}

bezier::bezier(const bsp_vertex* c)
{
	for (int i = 0; i < 9; ++i)
		controls[i] = c[i];
}

void bezier::tessellate(int L) {
    level = L;

    // The number of vertices along a side is 1 + num edges
    const int L1 = L + 1;

    vertex.resize(L1 * L1);

    // Compute the vertices
    int i;

    for (i = 0; i <= L; ++i) {
        float a = (float)i / L;
        float b = 1 - a;

        vertex[i] =
            controls[0] * (b * b) + 
            controls[3] * (2 * b * a) +
            controls[6] * (a * a);
    }

    for (i = 1; i <= L; ++i) {
        float a = (float)i / L;
        float b = 1.0f - a;

        bsp_vertex temp[3];

        int j;
        for (j = 0; j < 3; ++j) {
            int k = 3 * j;
            temp[j] =
                controls[k + 0] * (b * b) + 
                controls[k + 1] * (2 * b * a) +
                controls[k + 2] * (a * a);
        }

        for(j = 0; j <= L; ++j) {
            float a = (float)j / L;
            float b = 1.0f - a;

            vertex[i * L1 + j]=
                temp[0] * (b * b) + 
                temp[1] * (2 * b * a) +
                temp[2] * (a * a);
        }
    }


    // Compute the indices
    int row;
    indexes.resize(L * (L + 1) * 2);

    for (row = 0; row < L; ++row) {
        for(int col = 0; col <= L; ++col)	{
            indexes[(row * (L + 1) + col) * 2 + 1] = row       * L1 + col;
            indexes[(row * (L + 1) + col) * 2]     = (row + 1) * L1 + col;
        }
    }

    trianglesPerRow.resize(L);
    rowIndexes.resize(L);
    for (row = 0; row < L; ++row) {
        trianglesPerRow[row] = 2 * L1;
        rowIndexes[row]      = &indexes[row * 2 * L1];
    }
    
}

void bezier::draw() const
{
	const int stride = sizeof(bsp_vertex);
    glVertexPointer(3, GL_FLOAT, stride, &vertex[0].position);
	glNormalPointer(GL_FLOAT, stride, &vertex[0].normal);
	glColorPointer(4, GL_UNSIGNED_BYTE, stride, &vertex[0].color);

    glClientActiveTexture(GL_TEXTURE0);
    glTexCoordPointer(2, GL_FLOAT, stride, &vertex[0].texture_coordinate);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
    glClientActiveTexture(GL_TEXTURE1);
    glTexCoordPointer(2, GL_FLOAT, stride, &vertex[0].lightmap_coordinate);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
    //glMultiDrawElements(GL_TRIANGLE_STRIP, (GLsizei*)&trianglesPerRow[0], GL_UNSIGNED_INT, (const void **)(&rowIndexes[0]), level);
	for (int i = 0; i < level; ++i)
		glDrawElements(GL_TRIANGLE_STRIP, trianglesPerRow[i], GL_UNSIGNED_INT, rowIndexes[i]);
}

void bezier::add_faces(const NewtonCollision* tree) const
{
	for (int i = 0; i < level; ++i)
		for (int j = 0; j < (int)trianglesPerRow[i]-2; ++j)
		{
			bsp_vector3f triangle[3];
			triangle[0] = vertex[rowIndexes[i][j]].position;
			triangle[1] = vertex[rowIndexes[i][j+1]].position;
			triangle[2] = vertex[rowIndexes[i][j+2]].position;
			if (j % 2 == 0)
				std::swap(triangle[0], triangle[1]);
			NewtonTreeCollisionAddFace(tree, 3, (float*)triangle, sizeof(bsp_vector3f), 1);
		}
}

