#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Engine {
class Window {

  const int width;
  const int height;
  const char *title;

  GLFWwindow *window;

  void initWindow();

public:
  Window(int width, int height, const char *title);
  ~Window();

  Window(const Window &) = delete;
  auto operator=(const Window &) -> Window & = delete;

  auto shouldClose() -> bool;
  auto pollEvents() -> void;
  auto swapBuffers() -> void;

  auto createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) -> void;

  auto getGLFWWindow() -> GLFWwindow *;
};
} // namespace Engine