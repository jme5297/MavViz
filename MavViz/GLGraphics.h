#pragma once

#include "MVDataTypes.h"

namespace MavViz
{
	namespace Graphics
	{

		class Shader
		{
		public:
			GLchar* GetLog();
			int Configure(int shaderType, GLchar* sourceFile);
			void Delete();
			int GetID() { return ID; }

		protected:
			int shaderType;
			int ID;

			GLchar* source;
			GLchar* sourceFile;
		};

		class ShaderProg
		{
		public:
			int Link(Shader * vertShader, Shader * fragShader);
			void Use();

		protected:
			int ID;
			int success;
			Shader *vertexShader;
			Shader *fragShader;
		};
	}
}