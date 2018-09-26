#include "GLWindow.h"

GLFWwindow* MavViz::Graphics::initGLWindow(int w, int h)
{
	/* Instantiate The GLFW Window. */
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "MavViz", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window.\n";
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	/* Initialize GLAD before any OpenGL function is called. */
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD.\n";
		return NULL;
	}

	/* First OpenGL call - set the OpenGL viewport. */
	glViewport(0, 0, 800, 600);

	/* Window resize callback function */
	glfwSetFramebufferSizeCallback(window, MavViz::Graphics::framebuffer_size_callback);

	return window;
}

void MavViz::Graphics::framebuffer_size_callback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);
}

void MavViz::Graphics::processInput(GLFWwindow * window)
{
	/* Escape key */
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}