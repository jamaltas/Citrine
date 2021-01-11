#include <Citrine.h>



class ExampleLayer : public Citrine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//
		// Logs when window is updated;
		//
		//CT_INFO("ExampleLayer::Update");

		if (Citrine::Input::IsKeyPressed(CT_KEY_TAB))
			CT_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Citrine::Event& event) override
	{
		if (event.GetEventType() == Citrine::EventType::KeyPressed)
		{
			//
			// Because our keycodes from GLFW align with ASCII codes, we can 
			// cast the keycode as a char and get the keycode for letters.
			//
			Citrine::KeyPressedEvent& e = (Citrine::KeyPressedEvent&)event;
			if (e.GetKeyCode() == CT_KEY_TAB)
				CT_TRACE("Tab key is pressed (event)!");
			CT_TRACE("{0}", (char)e.GetKeyCode());
		}
		
		// Logs every event.
		//CT_TRACE("{0}", event);
	}

};


class Sandbox : public Citrine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Citrine::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Citrine::Application* Citrine::CreateApplication()
{
	return new Sandbox();
}