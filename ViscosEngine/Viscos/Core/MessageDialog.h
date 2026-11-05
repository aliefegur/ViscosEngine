#pragma once

#include "API.h"

#include <string_view>

namespace Viscos {

	class MessageDialog
	{
	public:
		enum class Type
		{
			Info,
			Warning,
			Error
		};

	public:
		VISCOS_API static void Show(std::string_view title, std::string_view message, Type type = Type::Info);
	};

}
