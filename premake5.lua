workspace "Render3D"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Render3D"
	location "Render3D"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "c++20"
		staticruntime "on"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines
		{
			"R3D_PLATFORM_WINDOWS",
			"R3D_DLL_BUILD"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
	
	filter "configurations:Debug"
		defines "R3D_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "R3D_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "R3D_DIST"
		optimize "on"

project "SandBox"
	location "SandBox"
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
		"Render3D/ThirdParty/spdlog/include",
		"Render3D/src"
	}

	links
	{
		"Render3D"
	}

	filter "system:windows"
		cppdialect "c++20"
		staticruntime "on"
		systemversion "latest"

		buildoptions { "/utf-8" }

		defines
		{
			"R3D_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "R3D_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "R3D_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "R3D_DIST"
		optimize "on"
