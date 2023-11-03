#pragma once

#include <vector>

namespace Engine {
class Pipeline {
  static std::vector<char> readFile(const char *filename);
  void createGraphicsPipeline(const char *vertexShaderPath,
                              const char *fragmentShaderPath);

public:
  Pipeline(const char *vertexShaderPath, const char *fragmentShaderPath);
  ~Pipeline();

  Pipeline(const Pipeline &) = delete;
  Pipeline &operator=(const Pipeline &) = delete;
};
} // namespace Engine
