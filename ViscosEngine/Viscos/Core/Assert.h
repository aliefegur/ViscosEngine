#pragma once

#include <cstdio>
#include <cstdlib>

namespace Viscos::Detail {

	[[noreturn]] inline void AssertionFailed(const char* experssion, const char* message, const char* file, int line) 
	{
		std::fprintf(stderr, "[Viscos Assertion Failed]\nExpression: %s\nMessage: %s\nFile: %s\nLine: %d\n", experssion, message, file, line);
		std::fflush(stderr);
		std::abort();
	}
	
}

#ifndef NDEBUG

#define VISCOS_ASSERT(condition, message)                 \
        do {                                                   \
            if (!(condition)) {                                \
                ::Viscos::Detail::AssertionFailed(             \
                    #condition, message, __FILE__, __LINE__);  \
            }                                                  \
        } while (false)

#else

#define VISCOS_ASSERT(condition, message) ((void)0)

#endif
