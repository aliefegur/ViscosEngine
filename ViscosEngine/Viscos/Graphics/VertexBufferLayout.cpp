#include "VertexBufferLayout.h"

namespace Viscos {

	VertexBufferLayout::VertexBufferLayout(size_t stride, std::initializer_list<VertexAttribute> attributes) 
		: m_Stride(stride), m_Attributes(attributes)
	{
	}

	size_t VertexBufferLayout::GetStride() const
	{
		return m_Stride;
	}

	const std::vector<VertexAttribute>& VertexBufferLayout::GetAttributes() const
	{
		return m_Attributes;
	}

}
