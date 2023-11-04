#include <vulkan_engine/pipeline.hpp>

#include <fstream>
#include <stdexcept>
#include <string>

namespace Engine {
Pipeline::Pipeline(Device &device, const char *vertexShaderPath,
                   const char *fragmentShaderPath,
                   const Pipeline::ConfigInfo &configInfo)
    : device{device} {
  createGraphicsPipeline(vertexShaderPath, fragmentShaderPath, configInfo);
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
                                      const char *fragmentShaderPath,
                                      const Pipeline::ConfigInfo &configInfo) {
  auto vertShaderCode = readFile(vertexShaderPath);
  auto fragShaderCode = readFile(fragmentShaderPath);
}

void Pipeline::createShaderModule(const std::vector<char> &code,
                                  VkShaderModule *shaderModule) {
  VkShaderModuleCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  createInfo.codeSize = code.size();
  createInfo.pCode = reinterpret_cast<const uint32_t *>(code.data());

  if (vkCreateShaderModule(device.device(), &createInfo, nullptr,
                           shaderModule) != VK_SUCCESS) {
    throw std::runtime_error("failed to create shader module!");
  }
}

Pipeline::ConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width,
                                                         uint32_t height) {
  Pipeline::ConfigInfo configInfo{};
  return configInfo;
}

} // namespace Engine