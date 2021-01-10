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
		CT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Citrine::Event& event) override
	{
		CT_TRACE("{0}", event);
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