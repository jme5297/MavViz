#pragma once

#include "MVDataTypes.h"

#include <iostream>

namespace MavViz
{
	namespace Graphics
	{
		/* Function prototypes */
		GLFWwindow* initGLWindow(int w, int h);
		void framebuffer_size_callback(GLFWwindow* window, int w, int h);
		void processInput(GLFWwindow * window);
	}
}