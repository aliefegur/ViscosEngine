#include <Viscos/Viscos.h>
#include <Viscos/Core/EntryPoint.h>

using namespace Viscos;

class TestLayer : public Viscos::Layer
{
public:
	TestLayer(const std::string& name) : Layer(name)
	{
	}

	void OnAttach() override
	{
		VSCS_INFO("{} attached", GetName());
	}

	void OnDetach() override
	{
		VSCS_INFO("{} detached", GetName());
	}

	void OnEvent(Event& e) override
	{
		VSCS_INFO("{} received event: {}", GetName(), e.ToString());
		e.Handled = true;
	}

	void OnUpdate() override
	{
		Renderer::Clear(1.0f, 1.0f, 0.0f, 0.0001f);
	}
};

class Sandbox : public Viscos::Application
{
public:
	Sandbox(const ApplicationSpecification& as) : Application(as)
	{
		auto testLayer = std::make_unique<TestLayer>("Gameplay");

		PushLayer(std::move(testLayer));
	}
};

Application* Viscos::CreateApplication()
{
	ApplicationSpecification as{};
	as.Name = "Viscos Engine Sandbox";

	return new Sandbox(as);
}
