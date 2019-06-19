#pragma once

// Set default OpenGL loader to be gl3w
#include "imgui.h"

IMGUI_IMPL_API bool     Imgui_Init(const char* glsl_version = NULL);
IMGUI_IMPL_API void     Imgui_Shutdown();
IMGUI_IMPL_API void     Imgui_NewFrame();
IMGUI_IMPL_API void     ImGui_RenderDrawData(ImDrawData* draw_data);

// Called by Init/NewFrame/Shutdown
IMGUI_IMPL_API bool     ImGui_CreateFontsTexture();
IMGUI_IMPL_API void     ImGui_DestroyFontsTexture();
IMGUI_IMPL_API bool     ImGui_CreateDeviceObjects();
IMGUI_IMPL_API void     ImGui_DestroyDeviceObjects();
