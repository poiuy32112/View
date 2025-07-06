#pragma once

#ifdef VI_PLATFORM_WINDOWS

extern View::Application* View::CreateApplication();

void main(int argc, char** argv)
{
	View::Log::Init();

	VI_PROFILE_BEGIN_SESSION("Startup", "ViewProfile-Startup.json");

	auto app = View::CreateApplication();
	VI_PROFILE_END_SESSION();

	VI_PROFILE_BEGIN_SESSION("Runtime", "ViewProfile-Runtime.json");
	app->Run();
	VI_PROFILE_END_SESSION();

	VI_PROFILE_BEGIN_SESSION("Shutdown", "ViewProfile-Shutdown.json");
	delete app;
	VI_PROFILE_END_SESSION();
}

#endif
