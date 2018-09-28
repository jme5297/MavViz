#include "GLGeomBasic.h"

using MavViz::Graphics::ShaderProg;
using MavViz::Graphics::Geometry::BasicGeo;

BasicGeo::BasicGeo(int dType, std::vector<glm::vec3> v, ShaderProg sp)
{
	drawType = dType;
	shaderProg = sp;
	int sz = v.size() * sizeof(glm::vec3);
	verts = v;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sz, &verts[0][0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BasicGeo::Draw()
{
	shaderProg.Use();
	glBindVertexArray(VAO);
	glDrawArrays(drawType, 0, verts.size());
	glBindVertexArray(0);
}

void BasicGeo::Clean()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}