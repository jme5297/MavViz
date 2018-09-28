#pragma once

#include "GLShader.h";

namespace MavViz
{
	namespace Graphics
	{
		namespace Geometry
		{
			class Triangle
			{
			public:
				Triangle();
				Triangle(float * vertices);
				Triangle(float * vertices, int VBO, int VAO);

				SetShaderProg(ShaderProg sp);
				Draw();

			protected:
				unsigned int VBO;
				unsigned int VAO;

			};
		}
	}
}