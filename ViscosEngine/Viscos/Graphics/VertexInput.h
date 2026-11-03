#pragma once

#include "Viscos/Core/API.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

#include <memory>

namespace Viscos {

	class VISCOS_API VertexInput
	{
	public:
		virtual ~VertexInput() = default;

		virtual void AddVertexBuffer(VertexBuffer& buffer, VertexBufferLayout& layout) = 0;
		virtual void SetIndexBuffer(IndexBuffer& buffer);

		virtual void Bind() = 0;

		const IndexBuffer& GetIndexBuffer() const;

		static std::unique_ptr<VertexInput> Create();

	protected:
		IndexBuffer* m_IndexBuffer;
	};

}
