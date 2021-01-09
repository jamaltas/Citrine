#pragma once

#ifdef CT_PLATFORM_WINDOWS

extern Citrine::Application* Citrine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Citrine::CreateApplication();
	app->Run();
	delete app;
}

#endif