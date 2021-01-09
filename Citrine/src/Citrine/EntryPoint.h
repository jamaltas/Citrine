#pragma once

#ifdef CT_PLATFORM_WINDOWS

extern Citrine::Application* Citrine::CreateApplication();

int main(int argc, char** argv)
{
	Citrine::Log::Init();

	CT_CORE_WARN("Initialized Log!");
	int a = 5;
	CT_INFO("Hello! Var={0}", a);


	auto app = Citrine::CreateApplication();
	app->Run();
	delete app;
}

#endif