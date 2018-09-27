#include "GLGraphics.h"
#include "MVIO.h"

using namespace std;
using namespace MavViz::Graphics;

int Shader::Configure(int sType, GLchar* sf)
{
	shaderType = sType;
	sourceFile = sf;
	source = MavViz::IO::loadShaderSource(sourceFile);
	if (source == NULL || strlen(source) == 0) return -1;
	ID = glCreateShader(shaderType);
	glShaderSource(ID, 1, &source, NULL);
	glCompileShader(ID);
	int success;
	glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
	if (!success) return -1;
	return 0;
}

void Shader::Delete()
{
	glDeleteShader(ID);
}

GLchar* Shader::GetLog()
{
	GLchar infoLog[512];
	glGetShaderInfoLog(ID, 512, NULL, infoLog);
	return infoLog;
}

int ShaderProg::Link(Shader *vs, Shader *fs)
{
	vertexShader = vs;
	fragShader = fs;
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader->GetID());
	glAttachShader(ID, fragShader->GetID());
	glLinkProgram(ID);

	int success = 0;
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (success)
	{
		vertexShader->Delete();
		fragShader->Delete();
		return 0;
	}
	else { return -1;  }
}

void ShaderProg::Use()
{
	glUseProgram(ID);
}