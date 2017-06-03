#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // THIS LINE IS FOR MAC_OSX

	// Create a window object to hold all of the windowing data
	GLFWwindow* window = glfwCreateWindow(800, 600, "My First Window", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// WE WANT TO INITIALIZE GLAD BEFORE WE CALL ANY OpenGL FUNCTIONS. (BUT WHY?)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// BEFORE RENDERING WE MUST TELL OpenGL THE SIZE OF THE RENDERING WINDOW SO THAT IT KNOWS HOW WE WANT TO DISPLAY THE DATA
	// AND COORDINATES WITH RESPECT TO THE WINDOW WE CREATED EARLIER (LINE 14). SO THAT IT KNOWS HOW TO DISPLAY THE DATA AND COORDS
	// IN RESPECT TO THE WINDOW. 
	glViewport(0, 0, 800, 600);

	// WRITING THE RENDER LOOP OR GAME LOOP
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}