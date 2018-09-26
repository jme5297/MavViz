#pragma once

#define SHADER_FILE_LEN 16777216 // 4096 * 4096

#include "MVDataTypes.h"
#include <iostream>
#include <fstream>

namespace MavViz
{
	namespace IO
	{
		int loadShaderSource(const char * fname, GLchar* source);
	}
}