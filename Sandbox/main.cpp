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
	}

	return 0;
}
