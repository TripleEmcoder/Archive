#pragma once
#include "newton.hpp"
#include "bsp_struct.hpp"
#include <vector>

class bezier 
{
private:
    int level;
	std::vector<bsp_vertex> vertex;
    std::vector<unsigned int> indexes;
    std::vector<unsigned int> trianglesPerRow;
    std::vector<unsigned int*> rowIndexes;

public:
    bsp_vertex controls[9];
    void tessellate(int level);
    void draw() const;
	void add_faces(const NewtonCollision* tree) const;

	bezier(const bsp_vertex* controls);
};