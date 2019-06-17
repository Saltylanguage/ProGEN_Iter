workspace "ProGEN_Iter"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Inclue directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ProGEN_Iter/ThirdParty/GLFW/include"
IncludeDir["Glad"] = "ProGEN_Iter/ThirdParty/Glad/include"
IncludeDir["imgui"] = "ProGEN_Iter/ThirdParty/imgui"

include "ProGEN_Iter/ThirdParty/GLFW"
include "ProGEN_Iter/ThirdParty/Glad"
include "ProGEN_Iter/ThirdParty/imgui"

project "ProGEN_Iter"
    location "ProGEN_Iter"
    kind "StaticLib"
    language "C++"
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        pchheader "GenPCH.h",   
        pchsource "ProGEN_Iter/src/GenPCH.cpp"
    }

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/ThirdParty/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.imgui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "imgui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    defines
    {
        "GEN_PLATFORM_WINDOWS",
        "GEN_BUILD_DLL",
        "GLFW_INCLUDE_NONE"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
        defines "GEN_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GEN_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "GEN_DIST"
        runtime "Release"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "ProGEN_Iter/ThirdParty/spdlog/include",
        "ProGEN_Iter/src"
    }

    links
    {
        "ProGEN_Iter"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

    defines
    {
        "GEN_PLATFORM_WINDOWS"
    }

    filter "configurations:Debug"
        defines "GEN_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "GEN_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "GEN_DIST"
        runtime "Release"
        optimize "On"
