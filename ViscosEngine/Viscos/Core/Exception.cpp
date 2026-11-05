#include "Exception.h"

namespace Viscos {

	ViscosException::ViscosException(std::string message, std::source_location location)
		:
		ViscosException("ViscosException", std::move(message), location)
	{
	}

	ViscosException::ViscosException(const ViscosException& other) = default;
	ViscosException::~ViscosException() = default;

	const char* ViscosException::what() const noexcept
	{
		return m_WhatBuffer.c_str();
	}

	const char* ViscosException::GetType() const noexcept
	{
		return m_Type.c_str();
	}

	const std::string& ViscosException::GetMsg() const noexcept
	{
		return m_Message;
	}

	const std::source_location& ViscosException::GetLocation() const noexcept
	{
		return m_Location;
	}

	ViscosException::ViscosException(std::string_view type, std::string message, std::source_location location)
		:
		m_Type(type),
		m_Message(std::move(message)),
		m_Location(location)
	{
		m_WhatBuffer.reserve(type.size() + m_Message.size() + 256);

		m_WhatBuffer += "[";
		m_WhatBuffer += type;
		m_WhatBuffer += "]\nMessage: ";
		m_WhatBuffer += m_Message;
		m_WhatBuffer += "\nFile: ";
		m_WhatBuffer += m_Location.file_name();
		m_WhatBuffer += "\nLine: ";
		m_WhatBuffer += std::to_string(m_Location.line());
		m_WhatBuffer += "\nFunction: ";
		m_WhatBuffer += m_Location.function_name();
	}

}
