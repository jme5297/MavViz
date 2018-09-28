#include "GLGeomBasic.h"

using MavViz::Graphics::ShaderProg;
using MavViz::Graphics::Geometry::BasicGeo;

BasicGeo::BasicGeo(float * v, int sz, ShaderProg sp)
{
	shaderProg = sp;
	memcpy(vertices, v, sz);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sz, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BasicGeo::Draw()
{
	shaderProg.Use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}