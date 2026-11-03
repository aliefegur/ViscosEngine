# Viscos Engine

Viscos Engine is a C++ game engine for indie-scale 2D and 3D games. Its initial development target is Windows PC. The long-term goal is to support stable releases on Windows, Linux, Android, and iOS.

## Vision and scope

The engine aims to give a small game team a common technical foundation across different kinds of projects. Driving games and 2D and 3D adventures are representative use cases. They give system design decisions a practical test: which parts of a feature would a second game reuse, and which parts belong to the first game's design?

## Technology and rendering roadmap

C++ is the engine's implementation language. Rendering support is planned in stages:

| Stage | Graphics API | Development goal |
| --- | --- | --- |
| 1 | OpenGL | Prototype rendering features quickly and test them on Windows PC. |
| 2 | Direct3D 11 | Implement a second backend and use it to establish a renderer-independent interface. |
| 3 | Direct3D 12 and Vulkan | Extend the rendering architecture to support additional graphics APIs. |

## How we build systems

**Start with a game requirement.** A 2D adventure and a driving game may both need to draw a scene, but they have different rules for how the camera follows the player. The motivation for a shared system is to let both games reuse the drawing code while each game controls its camera behavior.

**Test the rendering boundary with a second implementation.** An OpenGL prototype tells us what works with OpenGL. Implementing the same feature in Direct3D 11 gives us a concrete way to check whether game-facing code depends on OpenGL details. The goal is for a game to describe what it needs to draw while the backend handles the API-specific work.

**Validate features on Windows first.** New features start on Windows PC, where the team can test their behavior before bringing them to the other target platforms. This sets the order of development while keeping Linux, Android, and iOS in scope when designing platform-dependent systems.
