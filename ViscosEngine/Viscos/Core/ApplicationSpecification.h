#pragma once

#include "Viscos/Graphics/GraphicsAPI.h"

#include <string>

namespace Viscos {

	struct ApplicationSpecification
	{
		std::string Name = "Viscos Application";
		unsigned int Width = 1280;
		unsigned int Height = 720;
		GraphicsAPI GraphicsBackend = GraphicsAPI::OpenGL;
	};

}
