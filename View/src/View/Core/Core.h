#pragma once

#include <memory>

#ifdef VI_PLATFORM_WINDOWS
#if VI_DYNAMIC_LINK
#ifdef VIEW_BUILD_DLL
#define VIEW_API __declspec(dllexport)
#else
#define VIEW_API __declspec(dllimport)
#endif
#else
#define VIEW_API
#endif
#else
#error View only supports Windows!
#endif

// TODO: Make this macro able to take in no arguments except condition
#ifdef VI_ENABLE_ASSERTS
#define VI_ASSERT(x, ...) { if(!(x)) { VI_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define VI_CORE_ASSERT(x, ...) { if(!(x)) { VI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define VI_ASSERT(x, ...)
#define VI_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define VI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

//namespace View
//{
//
//    template<typename T>
//    using Scope = std::unique_ptr<T>;
//
//    template<typename T>
//    using Ref = std::shared_ptr<T>;
//
//}

namespace View
{

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}