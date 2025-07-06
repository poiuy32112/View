project "View"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vzpch.h"
	pchsource "src/vzpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"vendor/stb_image/**.h",
		"vendor/stb_image/**.cpp",
		"vendor/glm/glm/**.hpp",
		"vendor/glm/glm/**.inl",

		"vendor/ImGuizmo/ImGuizmo.h",
		"vendor/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
		"VI_PLATFORM_WINDOWS",
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
        	"YAML_CPP_STATIC_DEFINE"
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
		"vendor/glm",
		"vendor/entt/include",
		"vendor/stb_image",
		"vendor/ImGuizmo",
		"vendor/GLFW/include",
		"vendor/Glad/include",
		"vendor/imgui",
		"vendor/yaml-cpp/include"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib"
	}

	filter "files:vendor/ImGuizmo/**.cpp"
	flags { "NoPCH" }

	filter "files:vendor/stb_image/**.cpp"
	flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VIEW_BUILD_DLL",
		}

	filter "configurations:Debug"
		defines "VI_DEBUG"
		runtime "Debug"
		symbols "on"
		buildoptions "/utf-8"

	filter "configurations:Release"
		defines "VI_RELEASE"
		runtime "Release"
		optimize "on"
		buildoptions "/utf-8"

	filter "configurations:Dist"
		defines "VI_DIST"
		runtime "Release"
		optimize "on"
		buildoptions "/utf-8"