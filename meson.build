project('vulkan_engine', 'cpp', version: '0.0.1', default_options: ['cpp_std=c++23'])

dep = [ dependency('glfw3'), dependency('glm'), dependency('vulkan') ]

inc = include_directories('include')

vulkan_engine = library(
    'vulkan_engine',
    sources: [
        'src/device.cpp',
        'src/pipeline.cpp',
        'src/window.cpp'
    ],
    include_directories: inc,
    dependencies: dep,
    install: true
)

vulkan_engine_dep = declare_dependency(
    include_directories: inc,
    dependencies: dep,
    link_with: vulkan_engine
)