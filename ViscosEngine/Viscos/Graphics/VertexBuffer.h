#pragma once

#include "Viscos/Core/API.h"
#include "Buffer.h"

#include <memory>

namespace Viscos {

	class VISCOS_API VertexBuffer : public Buffer
	{
	public:
		using Buffer::Buffer;

		virtual ~VertexBuffer() = default;

		static std::unique_ptr<VertexBuffer> Create(const void* data, size_t size, Usage u);
	};

}
