#ifndef VULKAN_APPLICATION_HEADER
#define VULKAN_APPLICATION_HEADER

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <string.h>
#include <optional>
#include <set>
#include <algorithm>
#include <fstream>
#include <glm/glm.hpp>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include <chrono>

#include "Utils.h"

//#define ENABLE_MULTISAMPLING

class VulkanApplication {
    public:

        /*Main workflow*/
        void run();

    private:

        /*Main workflow*/
        void start();
        void loop();
        void finish();

        /*GLFW setup*/
        GLFWwindow* window;
        void setupWindow();
        void cleanupWindow();

        /*Vulkan instance setup*/
        VkInstance vulkanInstance;
        void setupVulkanInstance();
        void cleanupVulkanInstance();

        /*Debug messenger setup*/
        VkDebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfo{};
        VkDebugUtilsMessengerEXT debugMessenger;
        void setupDebugMessenger();
        void cleanupDebugMessenger();

        /*Physical device setup*/
        VkBool32 allowsAnisotropy;
        VkPhysicalDevice physicalDevice;
        void setupPhysicalDevice();

        /*Window surface setup*/
        VkSurfaceKHR surface;
        void setupWindowSurface();
        void cleanupWindowSurface();

        /*Logical device setup*/
        VkDevice device;
        VkQueue graphicsQueue;
        VkQueue presentQueue;
        void setupLogicalDevice();
        void cleanupLogicalDevice();

        /*Swap chain setup*/
        VkSwapchainKHR swapChain;
        std::vector<VkImage> swapChainImages;
        VkFormat swapChainImageFormat;
        VkExtent2D swapChainExtent;
        void setupSwapChain();
        void cleanupSwapChain();

        /*Image views setup*/
        std::vector<VkImageView> swapChainImageViews;
        void setupImageViews();
        void cleanupImageViews();

        /*Command buffers setup*/
        VkCommandPool commandPool;
        VkCommandPool temporaryCommandPool;
        std::vector<VkCommandBuffer> commandBuffers;
        void setupCommandBuffers();
        void cleanupCommandBuffers();

        /*Mutisampling setup*/
        #ifdef ENABLE_MULTISAMPLING
        VkSampleCountFlagBits msaaSamples;
        VkImage colorImage;
        VkDeviceMemory colorImageMemory;
        VkImageView colorImageView;
        void setupMultisampling();
        void cleanupMultisampling();
        #endif

        /*Depth buffering setup*/
        VkImage depthImage;
        VkDeviceMemory depthImageMemory;
        VkImageView depthImageView;
        void setupDepthBuffering();
        void cleanupDepthBuffering();

        /*Render passes setup*/
        VkRenderPass renderPass;
        void setupRenderPasses();
        void cleanupRenderPasses();

        /*Graphics pipeline setup*/
        VkDescriptorSetLayout descriptorSetLayout;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
        void setupGraphicsPipeline();
        void cleanupGraphicsPipeline();

        /*Framebuffers setup*/
        std::vector<VkFramebuffer> swapChainFramebuffers;
        void setupFramebuffers();
        void cleanupFramebuffers();

        /*Descriptor pool setup*/
        void setupDescriptorPool();
        void cleanupDescriptorPool();

        /*Rendering and presentation*/
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        void setupRenderingAndPresentation();
        void cleanupRenderingAndPresentation();
        void recordCommandBuffer(uint32_t inFlightFrame, uint32_t imageIndex);
        void drawFrame(uint32_t inFlightFrame);

        /*Vertex buffers setup*/
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        void setupVertexBuffers();
        void cleanupVertexBuffers();

        /*Uniform buffers setup*/
        std::vector<VkBuffer> uniformBuffers;
        std::vector<VkDeviceMemory> uniformBuffersMemory;
        std::vector<void*> uniformBuffersMapped;
        VkDescriptorPool descriptorPool;
        std::vector<VkDescriptorSet> descriptorSets;
        void setupUniformBuffers();
        void cleanupUniformBuffers();
        void updateUniformBuffer(uint32_t inFlightFrame);

        /*Texture mapping setup*/
        uint32_t mipLevels;
        VkImage textureImage;
        VkDeviceMemory textureImageMemory;
        VkImageView textureImageView;
        VkSampler textureSampler;
        void setupTextureMapping();
        void cleanupTextureMapping();
};

#endif