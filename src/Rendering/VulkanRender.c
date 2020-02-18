#include "VulkanRender.h"

#include <stdio.h>

#ifdef USING_VULKAN

#include "Render.h"

bool Render_Vulkan_Init(struct _Render* curRender)
{

    char* instance_validation_layers[] = { "VK_LAYER_KHRONOS_validation" };

    printf("Initalizing Render API Vulkan\n");

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    const VkApplicationInfo app = {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext = NULL,
        .pApplicationName = "TheBaseApp",
        .applicationVersion = 0,
        .pEngineName = "TheBase",
        .engineVersion = 0,
        .apiVersion = VK_API_VERSION_1_0,
    };
    VkInstanceCreateInfo inst_info = {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext = NULL,
        .pApplicationInfo = &app,
        .enabledLayerCount = 0,
        //.ppEnabledLayerNames = ?,
        .enabledExtensionCount = glfwExtensionCount,
        .ppEnabledExtensionNames = glfwExtensions,
    };

    VkResult result = vkCreateInstance(&inst_info, NULL, &curRender->vk_instance);

    if (result == VK_ERROR_INCOMPATIBLE_DRIVER) {
        //ERR_EXIT(
        //    "Cannot find a compatible Vulkan installable client driver (ICD).\n\n"
        //    "Please look at the Getting Started guide for additional information.\n",
        //    "vkCreateInstance Failure");
    }
    else if (result == VK_ERROR_EXTENSION_NOT_PRESENT) {
        //ERR_EXIT(
        //    "Cannot find a specified extension library.\n"
        //    "Make sure your layers path is set appropriately.\n",
        //    "vkCreateInstance Failure");
    }
    else if (result) {
        //ERR_EXIT(
        //    "vkCreateInstance failed.\n\n"
        //    "Do you have a compatible Vulkan installable client driver (ICD) installed?\n"
        //    "Please look at the Getting Started guide for additional information.\n",
        //    "vkCreateInstance Failure");
    }

    // Checking for extention support
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

    // Debug log loaded vulkan extention count

	return true;
}

void Render_Vulkan_Shutdown(struct _Render* curRender)
{
    vkDestroyInstance(curRender->vk_instance, NULL);
}

#endif