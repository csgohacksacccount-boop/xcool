#include "xcool/engine/engine.h"
#include "xcool/utils/logger.h"
#include "xcool/game/player_manager.h"
#include "xcool/game/game_state.h"
#include "xcool/render/renderer.h"
#include "xcool/render/esp.h"
#include "xcool/input/input_handler.h"

int main() {
    // Initialize logger
    xcool::Logger::Initialize("xcool.log");
    xcool::Logger::Info("========================================");
    xcool::Logger::Info("xcool - Roblox External Framework");
    xcool::Logger::Info("Version 1.0.0");
    xcool::Logger::Info("========================================");
    
    // Initialize engine
    xcool::Engine engine;
    if (!engine.Initialize()) {
        xcool::Logger::Error("Failed to initialize engine");
        return 1;
    }
    
    // Initialize subsystems
    xcool::PlayerManager::Get().Initialize();
    xcool::GameState::Get().Initialize();
    xcool::Renderer::Get().Initialize();
    xcool::ESP::Get().Initialize();
    xcool::InputHandler::Get().Initialize();
    
    xcool::Logger::Info("All subsystems initialized successfully");
    
    // Configure ESP
    xcool::ESP::Get().EnableOption(xcool::ESP::ESPOption::SHOW_BOXES);
    xcool::ESP::Get().EnableOption(xcool::ESP::ESPOption::SHOW_NAMES);
    xcool::ESP::Get().EnableOption(xcool::ESP::ESPOption::SHOW_HEALTH);
    xcool::ESP::Get().EnableOption(xcool::ESP::ESPOption::SHOW_DISTANCE);
    xcool::ESP::Get().SetMaxDistance(200.0f);
    
    // Register update callback
    engine.RegisterUpdateCallback("main_loop", [](float delta_time) {
        // Main game loop logic
        static int frame_count = 0;
        frame_count++;
        
        if (frame_count % 60 == 0) {
            xcool::Logger::Debug("Frame: " + std::to_string(frame_count) + 
                               " DeltaTime: " + std::to_string(delta_time));
        }
    });
    
    xcool::Logger::Info("Engine ready!");
    xcool::Logger::Info("Press F1 to toggle ESP");
    xcool::Logger::Info("Press ESC to exit");
    
    // Main loop
    int frame_count = 0;
    while (engine.IsRunning() && frame_count < 300) {  // Run for 5 seconds at 60 FPS
        engine.Update();
        
        // Example: Check for exit key
        // if (xcool::InputHandler::Get().IsKeyPressed(xcool::Key::F1)) {
        //     engine.SetRunning(false);
        // }
        
        frame_count++;
    }
    
    // Shutdown subsystems
    xcool::Logger::Info("Shutting down subsystems...");
    xcool::InputHandler::Get().Shutdown();
    xcool::ESP::Get().Shutdown();
    xcool::Renderer::Get().Shutdown();
    xcool::GameState::Get().Shutdown();
    xcool::PlayerManager::Get().Shutdown();
    
    // Shutdown engine
    engine.Shutdown();
    
    xcool::Logger::Info("========================================");
    xcool::Logger::Info("xcool shutdown successfully");
    xcool::Logger::Info("========================================");
    
    return 0;
}
