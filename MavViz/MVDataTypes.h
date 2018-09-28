#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>

struct Vertex2D
{
	double x;
	double y;
};

struct Vertex3D
{
	double x;
	double y;
	double z;
};

struct Triangle
{
	Vertex3D v1;
	Vertex3D v2;
	Vertex3D v3;
};
