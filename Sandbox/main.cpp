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
		VSCS_INFO("{} updated", GetName());
	}

	void OnRender() override
	{
		VSCS_INFO("{} rendered", GetName());
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
		VSCS_INFO("{} update", GetName());
	}

	void OnRender() override
	{
		VSCS_INFO("{} rendered", GetName());
	}
};

int main(int argc, char** argv)
{
	Log::Initialize();

	LayerStack stack;
	
	auto gameplay = std::make_unique<TestLayer>("Gameplay");
	auto debug = std::make_unique<TestLayer>("Debug");

	auto console = std::make_unique<TestOverlay>("Console");
	auto profiler = std::make_unique<TestOverlay>("Profiler");

	auto lateGameplay = std::make_unique<TestLayer>("LateGameplay");

	stack.PushLayer(std::move(gameplay));
	stack.PushLayer(std::move(debug));

	stack.PushOverlay(std::move(console));
	stack.PushOverlay(std::move(profiler));

	stack.PushLayer(std::move(lateGameplay));

	stack.OnUpdate();

	KeyPressedEvent e(45, false);
	stack.OnEvent(e);

	stack.OnRender();

	auto window = Window::Create({
		"Viscos Engine Sandbox Test Application",
		1280,
		720
	});

	window->SetEventCallback(
		[](Event& e) {
			VSCS_INFO("Event Recieved: {}", e.ToString());
		}
	);

	while (true)
	{		
		window->OnUpdate();

		if (Input::IsKeyPressed(KeyCode::W)) VSCS_TRACE("W Pressed!");
		if (Input::IsKeyPressed(KeyCode::A)) VSCS_TRACE("A Pressed!");
		if (Input::IsKeyPressed(KeyCode::S)) VSCS_TRACE("S Pressed!");
		if (Input::IsKeyPressed(KeyCode::D)) VSCS_TRACE("D Pressed!");
	}

	return 0;
}
