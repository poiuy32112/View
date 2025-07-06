project "Viewnut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	defines
    {
		"YAML_CPP_STATIC_DEFINE",
		"VI_PLATFORM_WINDOWS"
    }

	includedirs
	{
		"%{wks.location}/View/vendor/spdlog/include",
		"%{wks.location}/View/src",
		"%{wks.location}/View/vendor",
		"%{wks.location}/View/vendor/glm",
		"%{wks.location}/View/vendor/entt/include",
		"%{wks.location}/View/vendor/yaml-cpp/include",
		"%{wks.location}/View/vendor/ImGuizmo",
		"%{wks.location}/View/vendor/GLFW/include",
		"%{wks.location}/View/vendor/Glad/include",
		"%{wks.location}/View/vendor/imgui"
	}

	links
	{
		"View",
		"yaml-cpp"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "VI_DEBUG"
		buildoptions "/utf-8"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VI_RELEASE"
		buildoptions "/utf-8"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VI_DIST"
		buildoptions "/utf-8"
		runtime "Release"
		optimize "on"