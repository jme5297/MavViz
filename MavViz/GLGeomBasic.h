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
				BasicGeo(int drawType, std::vector<glm::vec3> vertices, ShaderProg sp);

				//SetShaderProg(ShaderProg sp);
				void Draw();
				void Clean();
				void SetDrawType(int dType) { drawType = dType; }

			protected:
				ShaderProg shaderProg;
				unsigned int VBO;
				unsigned int VAO;
				std::vector<glm::vec3> verts;
				int drawType;

			};
		}
	}
}