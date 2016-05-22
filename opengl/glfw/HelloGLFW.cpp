
#include <GLFW/glfw3.h>
#include <iostream>
#include <cassert>
#include <thread>


int main(void) {

    // Initialise GLFW
    glfwInit();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
