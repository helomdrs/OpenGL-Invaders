#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "ErrorHandler.h"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(540, 720, "OpenGL Invaders", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //determinates de framerate 
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;
    {
        Renderer renderer;

        /* Render loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
            renderer.Clear();

            GLCall(glfwSwapBuffers(window));
            GLCall(glfwPollEvents());
        }
    }

    glfwTerminate();

    return 0;
}