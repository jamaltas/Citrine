#pragma once

#include "Core.h"

namespace Citrine {

	class CITRINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined in CLIENT
	Application* CreateApplication();

}