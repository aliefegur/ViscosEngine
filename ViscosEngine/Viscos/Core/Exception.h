#pragma once

#include "API.h"

#include <exception>
#include <source_location>
#include <string>
#include <string_view>

namespace Viscos {

	class ViscosException : public std::exception
	{
	public:
		VISCOS_API explicit ViscosException(std::string message, std::source_location location = std::source_location::current());
		VISCOS_API ViscosException(const ViscosException& other);
		VISCOS_API ~ViscosException() override;

		VISCOS_API const char* what() const noexcept override;
		
		VISCOS_API const char* GetType() const noexcept;

		VISCOS_API const std::string& GetMsg() const noexcept;
		VISCOS_API const std::source_location& GetLocation() const noexcept;

	protected:
		VISCOS_API ViscosException(std::string_view type, std::string message, std::source_location location);

	private:
		std::string m_Message;
		std::string m_Type;
		std::string m_WhatBuffer;
		std::source_location m_Location;
	};

}
