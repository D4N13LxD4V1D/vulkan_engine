#pragma once

#include <vulkan_engine/device.hpp>

#include <vector>

namespace Engine {
struct PipelineConfigInfo {
  VkViewport viewport;
  VkRect2D scissor;
  VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
  VkPipelineRasterizationStateCreateInfo rasterizationInfo;
  VkPipelineMultisampleStateCreateInfo multisampleInfo;
  VkPipelineColorBlendAttachmentState colorBlendAttachment;
  VkPipelineColorBlendStateCreateInfo colorBlendInfo;
  VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
  VkPipelineLayout pipelineLayout = nullptr;
  VkRenderPass renderPass = nullptr;
  uint32_t subpass = 0;
};

class Pipeline {
  Device &device;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;

  PipelineConfigInfo configInfo;

  static auto readFile(const char *filename) -> std::vector<char>;

  auto createGraphicsPipeline(const char *vertexShaderPath,
                              const char *fragmentShaderPath,
                              const PipelineConfigInfo &configInfo) -> void;

  auto createShaderModule(const std::vector<char> &code,
                          VkShaderModule *shaderModule) -> void;

public:
  Pipeline(Device &device, const char *vertexShaderPath,
           const char *fragmentShaderPath,
           const PipelineConfigInfo &configInfo);
  ~Pipeline();

  Pipeline(const Pipeline &) = delete;
  auto operator=(const Pipeline &) -> Pipeline & = delete;

  static auto defaultPipelineConfigInfo(uint32_t width, uint32_t height)
      -> PipelineConfigInfo;
};
} // namespace Engine
