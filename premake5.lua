workspace "Citrine"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Citrine/vendor/Glad/include"
IncludeDir["ImGui"] = "Citrine/vendor/imgui"
IncludeDir["glm"] = "Citrine/vendor/glm"

include "Citrine/vendor/GLFW"
include "Citrine/vendor/Glad"
include "Citrine/vendor/imgui"


project "Citrine"
	location "Citrine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ctpch.h"
	pchsource "Citrine/src/ctpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"

	}


	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CT_PLATFORM_WINDOWS",
			"CT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "CT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CT_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Citrine/src",
		"Citrine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Citrine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CT_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CT_DIST"
		runtime "Release"
		optimize "on"
