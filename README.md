# xcool - Professional C++ Roblox External Framework

## Overview
xcool is a comprehensive, feature-rich C++ framework for Roblox external development with a full suite of advanced capabilities.

## Features

### Core Systems
- ✅ **Engine**: Main loop with FPS control and update callbacks
- ✅ **Memory Operations**: Direct read/write, pointer manipulation
- ✅ **Pattern Scanning**: Memory pattern detection and location
- ✅ **Hook Management**: Function hooking and detour system

### Game Integration
- ✅ **Player Manager**: Track and manage player data
- ✅ **Game State**: Monitor game mode, rounds, running state
- ✅ **Physics Engine**: Gravity, forces, raycasting simulation

### Rendering
- ✅ **2D/3D Drawing**: Lines, boxes, circles, triangles, text
- ✅ **World-to-Screen**: Coordinate transformation
- ✅ **ESP System**: Player boxes, names, health, distance, skeleton, snaplines
- ✅ **Text Rendering**: Screen-space and world-space

### Advanced Features
- ✅ **Lua Scripting**: Full Lua integration with C++ bindings
- ✅ **Networking**: TCP/UDP socket support
- ✅ **Configuration**: JSON-based settings management
- ✅ **Logging**: Multi-level logging system
- ✅ **Input Handling**: Keyboard/mouse input monitoring
- ✅ **Math Utilities**: Vectors, matrices, quaternions (GLM)
- ✅ **Memory Protection**: Cross-platform memory access

## Project Structure

```
xcool/
├── CMakeLists.txt              # Build configuration
├── include/xcool/              # Header files
│   ├── engine/                 # Engine core
│   ├── memory/                 # Memory operations
│   ├── game/                   # Game integration
│   ├── render/                 # Rendering system
│   ├── input/                  # Input handling
│   ├── utils/                  # Utilities
│   ├── offsets/               # Roblox offsets (276 offsets)
│   ├── scripting/             # Lua integration
│   └── network/               # Networking
├── src/                        # Implementation files
│   ├── main.cpp               # Entry point
│   └── [subsystem implementations]
└── .gitignore
```

## Building

### Requirements
- C++17 or later
- CMake 3.16+
- GLM (for math operations)

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
cmake --build . --config Release

# Run
./bin/xcool
```

## Platform Support
- ✅ Windows (MSVC, MinGW)
- ✅ Linux (GCC, Clang)
- ✅ macOS (Clang)

## Roblox Offsets
- **Version**: version-bf6344c9c23446bf
- **Total Offsets**: 276
- **Dumper**: roblox-dumper 2.6
- **Coverage**: 26 major Roblox classes and systems

## Usage Example

```cpp
#include "xcool/engine/engine.h"
#include "xcool/render/esp.h"

int main() {
    xcool::Engine engine;
    engine.Initialize();
    
    xcool::ESP::Get().SetEnabled(true);
    xcool::ESP::Get().EnableOption(xcool::ESP::ESPOption::SHOW_BOXES);
    
    while (engine.IsRunning()) {
        engine.Update();
    }
    
    engine.Shutdown();
    return 0;
}
```

## Architecture Highlights

### Memory Safety
- Cross-platform memory protection
- Safe pointer dereferencing
- Protected read/write operations

### Modular Design
- Independent subsystems
- Singleton pattern for core managers
- Clean separation of concerns

### Performance
- Efficient update loop
- Optimized rendering pipeline
- Minimal overhead logging

## Contributing
Feel free to extend xcool with additional features and integrations!

## License
This project is for educational purposes.

## Support
For issues and questions, refer to the comprehensive logging system and documentation.

---
**xcool v1.0.0** - Professional Roblox External Framework
