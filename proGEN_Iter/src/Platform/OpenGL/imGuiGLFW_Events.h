#pragma once

struct GLFWwindow;

IMGUI_IMPL_API bool     Vulkan_Init(GLFWwindow* window, bool install_callbacks);
IMGUI_IMPL_API bool     GLFW_Init(GLFWwindow* window, bool install_callbacks);
IMGUI_IMPL_API void     GLFW_Shutdown();
IMGUI_IMPL_API void     GLFW_NewFrame();

// InitXXX function with 'install_callbacks=true': install GLFW callbacks. They will call user's previously installed callbacks, if any.
// InitXXX function with 'install_callbacks=false': do not install GLFW callbacks. You will need to call them yourself from your own GLFW callbacks.
IMGUI_IMPL_API void     GLFW_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
IMGUI_IMPL_API void     GLFW_ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
IMGUI_IMPL_API void     GLFW_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
IMGUI_IMPL_API void     GLFW_CharCallback(GLFWwindow* window, unsigned int c);
