#pragma once

#include "Viscos/Core/API.h"

namespace Viscos {

	class VISCOS_API Buffer
	{
	public:
		enum class Usage
		{
			Static,
			Dynamic
		};

		virtual ~Buffer() = default;

		virtual void SetData(const void* data, size_t size, size_t offset) = 0;
		size_t GetSize();

		virtual void Bind() = 0;

		Usage GetUsage() const;

	protected:
		explicit Buffer(Usage u);
		const Usage m_Usage;
		size_t m_Size;
	};

}
