#include <Viscos/Viscos.h>

using namespace Viscos;

void RunEventTests();
void TestWindowResizeEvent();
void TestKeyPressedEvent();
void TestMouseMovedEvent();
void TestEventDispatcher();

int main(int argc, char** argv)
{
	Viscos::Log::Initialize();

	RunEventTests();

	return 0;
}

void RunEventTests()
{
	VSCS_TRACE("=== Event Sytem Test ===");

	TestWindowResizeEvent();
	TestKeyPressedEvent();
	TestMouseMovedEvent();
	TestEventDispatcher();

	VSCS_TRACE("=== Event Sytem Test Finished ===");
}

void TestWindowResizeEvent()
{
	WindowResizeEvent e(1920, 1080);

	VSCS_INFO("Event: {}", e.ToString());
	VSCS_INFO("Type: {}", int(e.GetEventType()));
	
	if (e.IsInCategory(EventCategoryWindow)) 
	{
		VSCS_INFO("Category: EventCategoryWindow ({})", e.GetCategoryFlags());
	}
}

void TestKeyPressedEvent()
{
	KeyPressedEvent e(65, false);

	VSCS_INFO("Event: {}", e.ToString());

	if (e.IsInCategory(EventCategoryKeyboard))
	{
		VSCS_INFO("Category: Keyboard");
	}

	if (e.IsInCategory(EventCategoryInput))
	{
		VSCS_INFO("Category: Input");
	}

	VSCS_INFO("Category Flags: {}", e.GetCategoryFlags());
	VSCS_INFO("Key: {}", e.GetKeyCode());
	VSCS_INFO("Repeat: {}", e.IsRepeat());
}

void TestMouseMovedEvent()
{
	MouseMovedEvent event(640.0f, 360.0f);

	VSCS_INFO("Event: {}", event.ToString());

	if (event.IsInCategory(EventCategoryInput))
	{
		VSCS_INFO("Category: Input");
	}
	if (event.IsInCategory(EventCategoryMouse))
	{
		VSCS_INFO("Category: Mouse");
	}

	VSCS_INFO("Category Flags: {}", event.GetCategoryFlags());
	VSCS_INFO("Position: ({}, {})", event.GetX(), event.GetY());
}

void TestEventDispatcher()
{
	KeyPressedEvent event(65, false);

	EventDispatcher dispatcher(event);

	const bool dispatched =
		dispatcher.Dispatch<KeyPressedEvent>(
			[](KeyPressedEvent& keyEvent)
			{
				VSCS_INFO(
					"Dispatcher caught KeyPressedEvent! Key={}",
					keyEvent.GetKeyCode()
				);

				return true;
			}
		);

	VSCS_INFO("Dispatched: {}", dispatched);
	VSCS_INFO("Handled: {}", event.Handled);
}
