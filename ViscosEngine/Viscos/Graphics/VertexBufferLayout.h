#pragma once

namespace Viscos {

	struct VertexAttribute
	{
		enum class Type
		{
			Float32,
			Int32,
			UInt32,
			Int16,
			UInt16,
			Int8,
			UInt8
		};

		Type Type;
		uint32_t ComponentCount;
		size_t Offset;
		bool Normalized = false;
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout(size_t stride, std::initializer_list<VertexAttribute> attributes);
		virtual ~VertexBufferLayout() = default;

		size_t GetStride() const;
		const std::vector<VertexAttribute>& GetAttributes() const;

	private:
		size_t m_Stride;
		std::vector<VertexAttribute> m_Attributes;
	};

}
