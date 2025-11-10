#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main() {

  /*****************************************************************/
  // Initialize GLFW
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    return -1;
  }

  // Set OpenGL version and profile (3.3 core)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  /*****************************************************************/
  // create window and initialize glad
  int res_w = 1920;
  int res_h = 1080;
  bool fullscreen = true;

  GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

  // Create a window
  GLFWwindow* window = glfwCreateWindow(res_w, res_h, "FlappyPigeon", monitor, nullptr);
  if (!window) {
    std::cerr << "Failed to create GLFW window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Load OpenGL function pointers using GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cerr << "Failed to initialize GLAD\n";
      return -1;
  }

  glViewport(0, 0, res_w, res_h);
  /*****************************************************************/

  // main loop
  while (!glfwWindowShouldClose(window)) {
    /*****************************************/
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Game p3
    // p3.mainloop()

    /*****************************************/
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Clean up
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
