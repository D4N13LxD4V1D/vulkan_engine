#pragma once

#include <vulkan_engine/device.hpp>

#include <vector>

namespace Engine {

class Pipeline {
  Device &device;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;

  struct ConfigInfo {

  } configInfo;

  static std::vector<char> readFile(const char *filename);

  void createGraphicsPipeline(const char *vertexShaderPath,
                              const char *fragmentShaderPath,
                              const ConfigInfo &configInfo);

  void createShaderModule(const std::vector<char> &code,
                          VkShaderModule *shaderModule);

public:
  Pipeline(Device &device, const char *vertexShaderPath,
           const char *fragmentShaderPath, const ConfigInfo &configInfo);
  ~Pipeline();

  Pipeline(const Pipeline &) = delete;
  Pipeline &operator=(const Pipeline &) = delete;

  static ConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
};
} // namespace Engine
