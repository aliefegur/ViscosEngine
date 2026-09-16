#pragma once

#include "API.h"

#include <string>

namespace Viscos {

	struct VISCOS_API ApplicationSpecification
	{
		std::string Name = "Viscos Application";
		unsigned int Width = 1280;
		unsigned int Height = 720;
	};

}
