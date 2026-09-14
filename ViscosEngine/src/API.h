#pragma once

#ifdef VISCOS_PLATFORM_WINDOWS
	#ifdef VISCOS_STATIC
		#define VISCOS_API
	#else
		#ifdef VISCOS_BUILD_DLL
			#define VISCOS_API __declspec(dllexport)
		#else
			#define VISCOS_API __declspec(dllimport)
		#endif
	#endif
#else
	#error "ViscosEngine currently supports only Windows!"
#endif

#ifndef VISCOS_API
	#warning "VISCOS_API not defined!"
	#define VISCOS_API
#endif
