workspace "Engine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}_%{cfg.system}_%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Engine/Vendor/Glfw/include"
IncludeDir["GLAD"] = "Engine/Vendor/Glad/include"
IncludeDir["IMGUI"] = "Engine/Vendor/Imgui"
IncludeDir["GLM"] = "Engine/Vendor/Glm"

include "Engine/Vendor/Glfw"
include "Engine/Vendor/Glad"
include "Engine/Vendor/Imgui"

project "Engine"
	location "Engine"
	kind "StaticLib"
	staticruntime "on"
	language "C++"
	cppdialect "C++20"

	targetdir ("_bin/" .. outputdir .. "/%{prj.name}")
	objdir ("_int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h" 
	pchsource "Engine/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Vendor/Glm/glm/**.hpp",
		"%{prj.name}/Vendor/Glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Vendor/Spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"IMGUI",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PLATFORM_WINDOWS",
			"BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("_bin/" .. outputdir .. "/%{prj.name}")
	objdir ("_int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Engine/Vendor/Spdlog/include",
		"Engine/src",
		"Engine/Vendor",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DIST"
		runtime "Release"
		optimize "on"