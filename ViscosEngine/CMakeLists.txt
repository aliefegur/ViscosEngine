cmake_minimum_required(VERSION 3.20)

option(VISCOS_BUILD_SHARED "Build ViscosEngine as a shared library (.dll/.so)" ON)

# Shared / Static build
if(VISCOS_BUILD_SHARED)
    add_library(ViscosEngine SHARED)
    target_compile_definitions(ViscosEngine PRIVATE VISCOS_BUILD_DLL)
else()
    add_library(ViscosEngine STATIC)
    target_compile_definitions(ViscosEngine PUBLIC VISCOS_STATIC)
endif()

target_compile_features(ViscosEngine PUBLIC cxx_std_20)
set_target_properties(ViscosEngine PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Platform definitions
if(WIN32)
    target_compile_definitions(ViscosEngine PUBLIC VISCOS_PLATFORM_WINDOWS)
elseif(ANDROID)
    target_compile_definitions(ViscosEngine PUBLIC VISCOS_PLATFORM_ANDROID)
elseif(IOS)
    target_compile_definitions(ViscosEngine PUBLIC VISCOS_PLATFORM_IOS)
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(ViscosEngine PUBLIC VISCOS_PLATFORM_LINUX)
elseif(APPLE)
    target_compile_definitions(ViscosEngine PUBLIC VISCOS_PLATFORM_MACOS)
endif()

# Source filles
target_sources(ViscosEngine 
    PRIVATE 
        Viscos/Core/Log.cpp
        Viscos/Events/Event.cpp
    PUBLIC FILE_SET HEADERS
        FILES 
            Viscos/Viscos.h
            Viscos/Core/API.h
            Viscos/Core/Log.h
            Viscos/Events/Event.h
            Viscos/Events/WindowEvents.h
            Viscos/Events/KeyEvents.h
)

# Incude directories
target_include_directories(ViscosEngine 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(ViscosEngine PUBLIC spdlog::spdlog)
