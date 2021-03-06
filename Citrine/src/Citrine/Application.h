#pragma once

#include "Core.h"

#include "Window.h"
#include "Citrine/LayerStack.h"
#include "Citrine/Events/Event.h"
#include "Citrine/Events/ApplicationEvent.h"

#include "Citrine/ImGui/ImGuiLayer.h"

namespace Citrine {

	class CITRINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window;  }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}