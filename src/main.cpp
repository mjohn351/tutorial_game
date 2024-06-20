#include <cstdio>
#include <cstdlib>
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
  if (!glfwInit())
  {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  GLFWwindow* window = glfwCreateWindow(800, 600, "Game Window", NULL, NULL);
  if (!window)
  {
    fprintf(stderr, "Failed to open GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwSetKeyCallback(window, key_callback);

  glfwMakeContextCurrent(window);

  // Main Loop to play game
  while (!glfwWindowShouldClose(window))
  {
    // Draw something
    // draw();

    // Update animation
    // animate();

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Destroy the window
  glfwDestroyWindow(window);

  // End program
  glfwTerminate();
  exit(EXIT_SUCCESS);

}
