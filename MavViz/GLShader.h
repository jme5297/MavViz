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
			ShaderProg() {};
			ShaderProg(GLchar * vertShaderSource, GLchar * fragShaderSource);

			int GetID() { return ID; }
			int Link();
			int Link(Shader  vertShader, Shader  fragShader);
			int Link(GLchar * vertShaderSource, GLchar * fragShaderSource);
			void Use();
			Shader* GetVertShader() { return &vertexShader; }
			Shader* GetFragShader() { return &fragmentShader; }

		protected:
			int ID;
			int success;
			Shader vertexShader;
			Shader fragmentShader;
		};
	}
}