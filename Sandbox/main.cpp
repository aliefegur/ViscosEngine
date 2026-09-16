#include <Viscos/Viscos.h>

using namespace Viscos;

class TestLayer : public Viscos::Layer
{
public:
	TestLayer()
		: Layer("TestLayer")
	{
	}

	void OnAttach() override
	{
		VSCS_INFO("TestLayer attached");
	}

	void OnDetach() override
	{
		VSCS_INFO("TestLayer detached");
	}

	void OnUpdate() override
	{
		VSCS_INFO("TestLayer updated");
	}
};

int main(int argc, char** argv)
{
	Log::Initialize();

	LayerStack stack;
	std::unique_ptr testLayer = std::make_unique<TestLayer>();
	stack.PushLayer(std::move(testLayer));

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
		stack.OnUpdate();
		
		window->OnUpdate();

		if (Input::IsKeyPressed(KeyCode::W)) VSCS_TRACE("W Pressed!");
		if (Input::IsKeyPressed(KeyCode::A)) VSCS_TRACE("A Pressed!");
		if (Input::IsKeyPressed(KeyCode::S)) VSCS_TRACE("S Pressed!");
		if (Input::IsKeyPressed(KeyCode::D)) VSCS_TRACE("D Pressed!");
	}

	return 0;
}
