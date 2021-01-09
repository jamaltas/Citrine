workspace "Citrine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Citrine/vendor/GLFW/include"

include "Citrine/vendor/GLFW"


project "Citrine"
	location "Citrine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ctpch.h"
	pchsource "Citrine/src/ctpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CT_PLATFORM_WINDOWS",
			"CT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CT_DIST"
		optimize "On"

		

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Citrine/vendor/spdlog/include;",
		"Citrine/src"
	}

	links
	{
		"Citrine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CT_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CT_DIST"
		optimize "On"