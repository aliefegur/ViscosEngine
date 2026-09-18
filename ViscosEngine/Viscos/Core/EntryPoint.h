#pragma once

#include "Application.h"

namespace Viscos {

	extern Application* CreateApplication();

}

int main(int argc, char** argv)
{
	auto app = Viscos::CreateApplication();
	
	app->Run();
	
	delete app;
	
	return 0;
}
