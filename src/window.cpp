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

auto Window::initWindow() -> void {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

auto Window::getExtent() -> VkExtent2D {
  return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
}

auto Window::shouldClose() -> bool { return glfwWindowShouldClose(window); }

auto Window::pollEvents() -> void { glfwPollEvents(); }

auto Window::swapBuffers() -> void { glfwSwapBuffers(window); }

auto Window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface)
    -> void {
  if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
    throw std::runtime_error("failed to create window surface!");
}

auto Window::getGLFWWindow() -> GLFWwindow * { return window; }

} // namespace Engine