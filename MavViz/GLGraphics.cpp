#include "GLGraphics.h"
#include "MVIO.h"

int MavViz::Graphics::loadShader(int shaderType, GLchar* source, unsigned int &shaderObject)
{
	GLchar* srctxt =  MavViz::IO::loadShaderSource(source);
	if (srctxt == NULL || strlen(srctxt) == 0) return -1;
	printf("%s\n", srctxt);

	shaderObject = glCreateShader(shaderType);
	glShaderSource(shaderObject, 1, &srctxt, NULL);
	glCompileShader(shaderObject);
	int success;
	char infoLog[512];
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(shaderObject, 512, NULL, infoLog);
	if (!success)
	{
		cout << "ERROR::SHADER::COMPILATION FAILED\n" << infoLog << endl;
		return -1;
	}
}

int MavViz::Graphics::initProg_vert_frag(unsigned int &vertexShader, unsigned int &fragShader, unsigned int &shaderProgram)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	if (!success) {
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return -1;
	}
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);

	return 0;
}