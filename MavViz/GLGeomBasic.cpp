#include "GLGeomBasic.h"

using namespace MavViz::Graphics;
using namespace MavViz::Graphics::Geometry;
using MavViz::Graphics::Geometry::Triangle;

Triangle::Triangle()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);


}