
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <iostream>
#include <cassert>
#include <thread>

void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void draw(GLFWwindow* window)
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    float ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    //glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    //glBegin(GL_TRIANGLES);
    //glColor3f(1.f, 0.f, 0.f);
    //glVertex3f(-0.6f, -0.4f, 0.f);
    //glColor3f(0.f, 1.f, 0.f);
    //glVertex3f(0.6f, -0.4f, 0.f);
    //glColor3f(0.f, 0.f, 1.f);
    //glVertex3f(0.f, 0.6f, 0.f);
    //glEnd();

}

int main(void) {

    // Initialise GLFW
    if (!glfwInit())
        return -1;

    glfwSetErrorCallback(error_callback);

    //std::this_thread::sleep_for(std::chrono::seconds(1));

    // Prepare window OpenGL settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr); // Windowed
    if (!window) 
    {
        glfwTerminate();
        return -1;
    }

    // Setup
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Run event loop
    while(!glfwWindowShouldClose(window))
    {
        draw(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
