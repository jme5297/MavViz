#include "GLGraphics.h"
#include "MVIO.h"

int MavViz::Graphics::loadShader(int shaderType, GLchar* source, unsigned int &shaderObject)
{
	GLchar * srctxt = (GLchar *)"";
	int a = MavViz::IO::loadShaderSource("C:\\MavViz\\Shaders\\vertexShader_basic.glsl", srctxt);
	if (a == -1) return -1;
	printf("%s\n", srctxt);

	shaderObject = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shaderObject, 1, &srctxt, NULL);
	glCompileShader(shaderObject);
	int success;
	char infoLog[512];
	glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderObject, 512, NULL, infoLog);
		cout << "ERROR::SHADER::COMPILATION FAILED\n" << infoLog << endl;
		return -1;
	}
}

int MavViz::Graphics::initProg_vert_frag(unsigned int &vertexShader, unsigned int &fragShader, unsigned int &shaderProgram, bool useProg)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);

	if (useProg)
	{
		glUseProgram(shaderProgram);
	}

	return 0;
}