#pragma once

#include "Viscos/Core/API.h"
#include "Buffer.h"

namespace Viscos {

	class VISCOS_API IndexBuffer : public Buffer
	{
	public:
		enum class Type
		{
			Uint16,
			Uint32
		};

		IndexBuffer(Usage u, Type t);
		virtual ~IndexBuffer() = default;

		Type GetType() const;

		size_t GetIndexSize() const;

		static std::unique_ptr<IndexBuffer> Create(const void* data, size_t size, Usage u, Type t);
	
	protected:
		Type m_Type;
	};

}
