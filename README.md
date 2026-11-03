# Viscos Engine

Viscos Engine is an open-source, general-purpose game engine written in C++20. The project explores computer graphics, framework design, and engine architecture through a working implementation. Its source code and engineering documentation provide a reference for developers studying how game engines are built.

## Design goals

Viscos aims to provide a clear, consistent interface for independent developers building 2D and 3D games. A central design goal is to let applications use the same engine interfaces across operating systems and graphics APIs. The project documents the reasoning behind those interfaces and the trade-offs encountered during development.

## Development scope

The initial foundation includes window management, events, input, logging, application layers, and the main loop. The engine core and sandbox application use CMake, with Visual Studio as the Windows development environment and spdlog for logging. The next phase focuses on runtime timing and rendering architecture.

## Platform and rendering roadmap

64-bit Windows is the first target for stable releases and the initial test platform for new features. Linux, Android, and iOS are longer-term targets.

| Planned graphics backend | Purpose |
| --- | --- |
| OpenGL | Prototype rendering features on Windows and establish the initial rendering interface. |
| Direct3D 11 | Validate and refine that interface against a second graphics API. |
| Direct3D 12 and Vulkan | Extend backend support once the common interface has been tested with OpenGL and Direct3D 11. |
