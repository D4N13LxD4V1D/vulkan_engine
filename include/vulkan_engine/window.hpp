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
  Window &operator=(const Window &) = delete;

  bool shouldClose();
  void pollEvents();
  void swapBuffers();

  void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

  GLFWwindow *getGLFWWindow();
};
} // namespace Engine