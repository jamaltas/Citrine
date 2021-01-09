#include "Application.h"

#include "Citrine/Events/ApplicationEvent.h"
#include "Citrine/Log.h"

namespace Citrine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CT_TRACE(e);
		

		while(true);
	}

}
