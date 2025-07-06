workspace "View"
	architecture "x64"
	startproject "Viewnut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "View/vendor/GLFW/include"
IncludeDir["Glad"] = "View/vendor/Glad/include"
IncludeDir["ImGui"] = "View/vendor/imgui"
IncludeDir["glm"] = "View/vendor/glm"
IncludeDir["stb_image"] = "View/vendor/stb_image"
IncludeDir["entt"] = "View/vendor/entt/include"
IncludeDir["yaml_cpp"] = "View/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "View/vendor/ImGuizmo"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

Library = {}
Library["Vulkan"] = "%{VULKAN_SDK}/Lib/vulkan-1.lib"
Library["VulkanUtils"] = "%{VULKAN_SDK}/Lib/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{VULKAN_SDK}/Lib/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{VULKAN_SDK}/Lib/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{VULKAN_SDK}/Lib/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{VULKAN_SDK}/Lib/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{VULKAN_SDK}/Lib/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{VULKAN_SDK}/Lib/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{VULKAN_SDK}/Lib/spirv-cross-glsl.lib"

group "Dependencies"
	include "View/vendor/GLFW"
	include "View/vendor/Glad"
	include "View/vendor/imgui"
	include "View/vendor/yaml-cpp"

group ""

include "View"
include "Sandbox"
include "Viewnut"