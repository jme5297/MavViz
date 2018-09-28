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
	BasicGeo triangle(
		GL_TRIANGLES, 
		std::vector<glm::vec3>{
			{-.7f, -.7f, 0.f},
			{ -.7f,  .7f, 0.f },
			{ .7f,  0.f, 0.f }
		},
		ShaderProg((GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.vert", (GLchar*)"C:\\MavViz\\Shaders\\rainbow.frag")
	);

	/* Main render loop */
	while (!glfwWindowShouldClose(window))
	{
		/* Process user input */
		MavViz::Graphics::processInput(window);

		float t = glfwGetTime();
		printf("%f\n", t);
		triangle.SetDrawType(((int)t % 2 == 0) ? GL_LINE_STRIP : GL_TRIANGLES);

		/* Rendering commands */
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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