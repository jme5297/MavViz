#include "GLWindow.h"
#include "GLShader.h"
#include "GLGeomBasic.h"
#include "MVIO.h"

using MavViz::Graphics::Shader;
using MavViz::Graphics::ShaderProg;
using MavViz::Graphics::Geometry::BasicGeo;

int main()
{
	GLFWwindow * window = MavViz::Graphics::initGLWindow(800, 600);

	/* Create a triangle. */
	/* Create some shaders. */
	ShaderProg spR((GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.vert", (GLchar*)"C:\\MavViz\\Shaders\\fragShader_red.frag");
	ShaderProg spB((GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.vert", (GLchar*)"C:\\MavViz\\Shaders\\fragShader_blue.frag");
	float verts[] = {
		-0.5f, -0.5f, 0.f,
		-0.5f,  0.5f, 0.f,
		 0.f,  -0.5f, 0.f
	};
	BasicGeo triangle(verts, sizeof(verts), spR);

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	/* Main render loop */
	while (!glfwWindowShouldClose(window))
	{
		/* Process user input */
		MavViz::Graphics::processInput(window);

		printf("%f\n", glfwGetTime());

		/* Rendering commands */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		triangle.Draw();

		/* Check events, swap buffers */
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/* Terminate GLFW. */
	glfwTerminate();
	return 0;
}