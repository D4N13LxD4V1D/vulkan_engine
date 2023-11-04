#include <vulkan_engine/window.hpp>

#include <stdexcept>

namespace Engine {

Window::Window(int width, int height, const char *title)
    : width(width), height(height), title(title) {
  initWindow();
}

Window::~Window() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void Window::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

bool Window::shouldClose() { return glfwWindowShouldClose(window); }

void Window::pollEvents() { glfwPollEvents(); }

void Window::swapBuffers() { glfwSwapBuffers(window); }

void Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
  if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
    throw std::runtime_error("failed to create window surface!");
}

GLFWwindow *Window::getGLFWWindow() { return window; }

} // namespace Engine