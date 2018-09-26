#include "GLWindow.h"
#include "GLGraphics.h"
#include "MVIO.h"

int main()
{

	GLFWwindow * window = MavViz::Graphics::initGLWindow(800, 600);

	float myTriangle[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	/* Create buffer object */
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(myTriangle), myTriangle, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	/* Load and compile the vertex and fragment shader. */
	unsigned int vertexShader;
	GLchar * vsSrc = (GLchar*)"C:\\MavViz\\Shaders\\vertexShader_basic.glsl";
	if (MavViz::Graphics::loadShader(GL_VERTEX_SHADER, vsSrc, vertexShader) == -1) return -1;

	unsigned int fragShader;
	GLchar * fsSrc = (GLchar*)"C:\\MavViz\\Shaders\\fragShader_basic.glsl";
	if (MavViz::Graphics::loadShader(GL_FRAGMENT_SHADER, fsSrc, fragShader) == -1) return -1;

	unsigned int shaderProgram;
	if (MavViz::Graphics::initProg_vert_frag(vertexShader, fragShader, shaderProgram, true) == -1) return -1;
	

	/* Main render loop */
	while (!glfwWindowShouldClose(window))
	{
		/* Process user input */
		MavViz::Graphics::processInput(window);

		/* Rendering commands */
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/* Draw the triangle. */
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/* Check events, swap buffers */
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	/* Terminate GLFW. */
	glfwTerminate();
	return 0;
}