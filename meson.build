project('vulkan_engine', 'cpp', version: '0.0.1')

glfw = dependency('glfw3')
glm = dependency('glm')
volk = import('cmake').subproject('volk').dependency('volk')

dep = [glfw, glm, volk]

if host_machine.system() == 'darwin'
    dep += [dependency('Cocoa', 'IOKit', 'CoreVideo')]
endif

inc = include_directories('include')

vulkan_engine = library(
    'vulkan_engine',
    sources: [
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