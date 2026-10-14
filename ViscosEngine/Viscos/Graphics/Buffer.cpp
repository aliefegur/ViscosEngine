#include "Buffer.h"

namespace Viscos {
	
	Buffer::Buffer(Usage u) : m_Usage(u)
	{
	}

	size_t Buffer::GetSize() const
	{
		return m_Size;
	}

	Buffer::Usage Buffer::GetUsage() const
	{
		return m_Usage;
	}

}
