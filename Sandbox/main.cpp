#include <Viscos/Viscos.h>
#include <Viscos/Events/KeyEvents.h>

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
		VSCS_INFO("{} handled event: {}", GetName(), e.ToString());
	}

	void OnUpdate() override
	{
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
		VSCS_INFO("{} received event: {}", GetName(), e.ToString());
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

int main(int argc, char** argv)
{
	ApplicationSpecification as{};
	as.Name = "Viscos Engine Sandbox";

	Application app(as);

	auto testLayer = std::make_unique<TestLayer>("Gameplay");
	auto testOverlay = std::make_unique<TestOverlay>("Debug");

	app.PushLayer(std::move(testLayer));
	app.PushOverlay(std::move(testOverlay));

	app.Run();

	return 0;
}
