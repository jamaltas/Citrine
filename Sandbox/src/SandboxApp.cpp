#include <Citrine.h>

class Sandbox : public Citrine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Citrine::Application* Citrine::CreateApplication()
{
	return new Sandbox();
}