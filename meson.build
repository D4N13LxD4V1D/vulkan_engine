project('vulkan_engine', 'cpp', version: '0.0.1', default_options: ['cpp_std=c++23'])

inc = include_directories('include')
dep = [ dependency('glfw3'), dependency('glm'), dependency('vulkan') ]
vulkan_engine = declare_dependency(
    include_directories: inc,
    dependencies: dep,
    link_with: library(
        'vulkan_engine',
        sources: [
            'src/device.cpp',
            'src/pipeline.cpp',
            'src/window.cpp',
            'src/swapchain.cpp',
        ],
        include_directories: inc,
        dependencies: dep,
        install: true
    )
)