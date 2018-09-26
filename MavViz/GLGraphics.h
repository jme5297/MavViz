#pragma once

#include "MVDataTypes.h"

namespace MavViz
{
	namespace Graphics
	{
		using namespace std;
		int loadShader(int shaderType, GLchar* source, unsigned int &shaderObject);
		int initProg_vert_frag(unsigned int &vertexShader, unsigned int &fragShader, unsigned int &shaderProgram, bool useProg);
	}
}