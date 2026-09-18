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
		/*VSCS_INFO("{} handled event: {}", GetName(), e.ToString());*/
	}

	void OnUpdate() override
	{
		if (Input::IsKeyPressed(KeyCode::Escape))
		{
			VSCS_INFO("ESC Key Pressed!");
		}
		//VSCS_INFO("{} updated", GetName());
	}

	void OnRender() override
	{
		//VSCS_INFO("{} rendered", GetName());
	}
};

class TestOverlay : public Overlay
{
public:
	TestOverlay(const std::string& name) : Overlay(name)
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
		/*VSCS_INFO("{} received event: {}", GetName(), e.ToString());*/
	}

	void OnUpdate() override
	{
		//VSCS_INFO("{} update", GetName());
	}

	void OnRender() override
	{
		//VSCS_INFO("{} rendered", GetName());
	}
};

class Sandbox : public Viscos::Application
{
public:
	Sandbox(const ApplicationSpecification& as) : Application(as)
	{
		auto testLayer = std::make_unique<TestLayer>("Gameplay");
		auto testOverlay = std::make_unique<TestOverlay>("Debug");

		PushLayer(std::move(testLayer));
		PushOverlay(std::move(testOverlay));
	}
};

Application* Viscos::CreateApplication()
{
	ApplicationSpecification as{};
	as.Name = "Viscos Engine Sandbox";

	return new Sandbox(as);
}
