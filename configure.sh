#!/bin/bash
VULKAN_SDK=/home/tiago-nascimento/tiago/workspace/3d-studies/vulkan-sdk/1.2.170.0/x86_64;
GLSLC=/home/tiago-nascimento/tiago/workspace/3d-studies/glslc;
export PATH=$VULKAN_SDK/bin:$GLSLC/bin:$PATH;
export VK_LAYER_PATH=$VULKAN_SDK/etc/explicit_layer.d;
export LD_LIBRARY_PATH=$VULKAN_SDK/lib:$LD_LIBRARY_PATH;
#export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_standard_validation; #ONLY ENABLE WHEN DEBUGGING!
