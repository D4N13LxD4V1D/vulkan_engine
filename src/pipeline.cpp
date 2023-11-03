#include <vulkan_engine/pipeline.hpp>

#include <iostream>

#include <fstream>
#include <stdexcept>
#include <string>

namespace Engine {
Pipeline::Pipeline(const char *vertexShaderPath,
                   const char *fragmentShaderPath) {
  createGraphicsPipeline(vertexShaderPath, fragmentShaderPath);
}

Pipeline::~Pipeline() {}

std::vector<char> Pipeline::readFile(const char *filename) {
  std::ifstream file(filename, std::ios::ate | std::ios::binary);
  if (!file.is_open())
    throw std::runtime_error("Failed to open file: " + std::string{filename});

  size_t fileSize = static_cast<size_t>(file.tellg());
  std::vector<char> buffer(fileSize);

  file.seekg(0);
  file.read(buffer.data(), fileSize);

  file.close();
  return buffer;
}

void Pipeline::createGraphicsPipeline(const char *vertexShaderPath,
                                      const char *fragmentShaderPath) {
  auto vertShaderCode = readFile(vertexShaderPath);
  auto fragShaderCode = readFile(fragmentShaderPath);

  std::cout << "Vertex shader size: " << vertShaderCode.size() << std::endl;
  std::cout << "Fragment shader size: " << fragShaderCode.size() << std::endl;
}

} // namespace Engine