workspace "ProGEN_Iter"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ProGEN_Iter"
    location "ProGEN_Iter"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

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
        "%{prj.name}/ThirdParty/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GEN_PLATFORM_WINDOWS",
            "GEN_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "GEN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GEN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GEN_DIST"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files
    {
        "%{prj.name}src",
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
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GEN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "GEN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GEN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GEN_DIST"
            symbols "On"
