#pragma once

#include "GLShader.h";

namespace MavViz
{
	namespace Graphics
	{
		namespace Geometry
		{

			class BasicGeo
			{
			public:
				BasicGeo() {};
				BasicGeo(float * vertices, int sz, ShaderProg sp);

				//SetShaderProg(ShaderProg sp);
				void Draw();

			protected:
				ShaderProg shaderProg;
				unsigned int VBO;
				unsigned int VAO;
				float vertices[];

			};
		}
	}
}