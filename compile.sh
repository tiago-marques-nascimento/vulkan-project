#!/bin/bash
VULKAN_SDK=/home/tiago-nascimento/tiago/workspace/3d-studies/vulkan-sdk/1.2.170.0/x86_64;
g++ -DVK_NO_PROTOTYPES \
    -DVK_USE_PLATFORM_XLIB_KHR \
    -I$VULKAN_SDK/include \
    VulkanFunctions.cpp \
    main.cpp \
    -ldl -lX11;
