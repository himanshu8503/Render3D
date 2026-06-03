workspace "Render3D"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

startproject "SandBox"

-- Include Directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Render3D/ThirdParty/GLFW/include"
IncludeDir["Glad"] = "Render3D/ThirdParty/Glad/include"
IncludeDir["imgui"] = "Render3D/ThirdParty/imgui"

-- GLFW project

include "Render3D/ThirdParty/GLFW"

--Glad Project

include "Render3D/ThirdParty/Glad"

-- imgui project
include "Render3D/ThirdParty/imgui"

-- Render3D project

project "Render3D"
	location "Render3D"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "R3Dpch.h"
	pchsource "Render3D/src/R3Dpch.cpp"

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
		cppdialect "c++20"
		systemversion "latest"
		disablewarnings { "4251" }
		buildoptions { "/utf-8" }

		defines
		{
			"R3D_PLATFORM_WINDOWS",
			"R3D_DLL_BUILD",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
	
	filter "configurations:Debug"
		defines "R3D_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "R3D_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "R3D_DIST"
		runtime "Release"
		optimize "on"


-- SandBox project

project "SandBox"
	location "SandBox"
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
		"Render3D/ThirdParty/spdlog/include",
		"Render3D/ThirdParty/imgui/",
		"Render3D/src"
	}

	links
	{
		"Render3D"
	}

	filter "system:windows"
		cppdialect "c++20"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines
		{
			"R3D_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "R3D_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "R3D_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "R3D_DIST"
		runtime "Release"
		optimize "on"
