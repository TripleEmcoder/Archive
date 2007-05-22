#include "bezier.hpp"
#include "engine.hpp"

bsp_vertex operator*(const bsp_vertex& v, const float x)
{
	bsp_vertex result(v);

	result.position.x *= x;
	result.position.y *= x;
	result.position.z *= x;

	result.texture_coordinate.x *= x;
	result.texture_coordinate.y *= x;
	
	result.lightmap_coordinate.x *= x;
	result.lightmap_coordinate.y *= x;
	return result;
}

bsp_vertex operator+(const bsp_vertex& l, const bsp_vertex& r)
{
	bsp_vertex result;

	result.position.x = l.position.x + r.position.x;
	result.position.y = l.position.y + r.position.y;
	result.position.z = l.position.z + r.position.z;

	result.texture_coordinate.x = l.texture_coordinate.x + r.texture_coordinate.x;
	result.texture_coordinate.y = l.texture_coordinate.y + r.texture_coordinate.y;
	
	result.lightmap_coordinate.x = l.lightmap_coordinate.x + r.lightmap_coordinate.x;
	result.lightmap_coordinate.y = l.lightmap_coordinate.y + r.lightmap_coordinate.y;

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

    glClientActiveTexture(GL_TEXTURE0);
    glTexCoordPointer(2, GL_FLOAT, stride, &vertex[0].texture_coordinate);

    glClientActiveTexture(GL_TEXTURE1);
    glTexCoordPointer(2, GL_FLOAT, stride, &vertex[0].lightmap_coordinate);

    glMultiDrawElements(GL_TRIANGLE_STRIP, (GLsizei*)&trianglesPerRow[0], GL_UNSIGNED_INT, (const void **)(&rowIndexes[0]), level);
}

