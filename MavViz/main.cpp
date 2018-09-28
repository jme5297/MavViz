#include "GLWindow.h"
#include "GLShader.h"
#include "MVIO.h"

using MavViz::Graphics::Shader;
using MavViz::Graphics::ShaderProg;

int main()
{
	GLFWwindow * window = MavViz::Graphics::initGLWindow(800, 600);

	float tLeft[] = {
		-0.5f, -0.5f, 0.f,
		-0.5f, 0.5f, 0.f,
		0.f, -0.5f, 0.f
	};
	
	float tRight[] = {
		0.f, 0.5f, 0.f,
		0.5f, 0.5f, 0.f,
		0.5f, -0.5f, 0.f
	};

	ShaderProg spR((GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.vert", (GLchar*)"C:\\MavViz\\Shaders\\fragShader_red.frag");
	ShaderProg spB((GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.vert", (GLchar*)"C:\\MavViz\\Shaders\\fragShader_blue.frag");


	// This should all be updated.
	/*
	unsigned int VAO[2];
	unsigned int VBO[2];
	glGenVertexArrays(2, VAO);
	glGenBuffers(2, VBO);

	glBindVertexArray(VAO[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tLeft), tLeft, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tRight), tRight, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	*/

	/* Main render loop */
	while (!glfwWindowShouldClose(window))
	{
		/* Process user input */
		MavViz::Graphics::processInput(window);

		/* Rendering commands */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Draw the triangle. */
		spR.Use();
		glBindVertexArray(VAO[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		spB.Use();
		glBindVertexArray(VAO[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/* Check events, swap buffers */
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/* Terminate GLFW. */
	glfwTerminate();
	return 0;
}