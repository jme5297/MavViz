#include "GLWindow.h"
#include "GLGraphics.h"
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

	/* Load and compile the vertex and fragment shader. */
	GLchar * vsSrc = (GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.glsl"; 
	GLchar * fsSrcR = (GLchar*)"C:\\MavViz\\Shaders\\fragShader_red.glsl";
	GLchar * fsSrcB = (GLchar*)"C:\\MavViz\\Shaders\\fragShader_blue.glsl";
	Shader vs, fsR, fsB;
	if (vs.Configure(GL_VERTEX_SHADER, vsSrc) != 0 || fsR.Configure(GL_FRAGMENT_SHADER, fsSrcR) != 0 || fsB.Configure(GL_FRAGMENT_SHADER, fsSrcB) != 0)
	{
		std::cout << vs.GetLog() << std::endl << fsR.GetLog() << std::endl << fsB.GetLog() << std::endl;
		return -1;
	}

	ShaderProg spR, spB;
	if (spR.Link(&vs, &fsR) != 0 || spB.Link(&vs, &fsB) != 0)
	{
		std::cout << "Linking error.\n";
		return -1;
	}

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

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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