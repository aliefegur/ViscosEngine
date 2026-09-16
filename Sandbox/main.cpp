#include <Viscos/Viscos.h>

using namespace Viscos;

int main(int argc, char** argv)
{
	Log::Initialize();

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
