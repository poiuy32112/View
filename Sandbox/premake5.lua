project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/View/vendor/spdlog/include",
		"%{wks.location}/View/src",
		"%{wks.location}/View/vendor",
		"%{wks.location}/View/vendor/glm",
		"%{wks.location}/View/vendor/entt/include",
		"%{wks.location}/View/vendor/ImGuizmo",
		"%{wks.location}/View/vendor/GLFW/include",
		"%{wks.location}/View/vendor/Glad/include",
		"%{wks.location}/View/vendor/imgui",
		"%{wks.location}/View/vendor/yaml-cpp/include"
	}

	links
	{
		"View"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VI_PLATFORM_WINDOWS"
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