#pragma once

#include "Viscos/Core/API.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

namespace Viscos {

	class VISCOS_API VertexInput
	{
	public:
		virtual ~VertexInput() = default;

		virtual void AddVertexBuffer(VertexBuffer& buffer, VertexBufferLayout& layout) = 0;
		virtual void SetIndexBuffer(IndexBuffer& buffer) = 0;

		virtual void Bind() = 0;

		static std::unique_ptr<VertexInput> Create();
	};

}
