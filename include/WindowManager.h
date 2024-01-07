#pragma once

#include <raylib.h>
#include <iostream>
#include <memory>
#include <mutex>
#include "Constants.h"
#include "FunctionParams.h"

#define MONITOR 0

namespace tv
{
   class WindowManager
   {
   public:
      /// @brief Constructor
      /// @param res: Window resolution
      /// @param windowName: Window name
      /// @param initScene: First scene
      WindowManager(Vector2 res, std::string windowName, enums::SCENE initScene);

      /// @brief Delete default constructor
      WindowManager() = delete;

      /// @brief Delete copy constructor
      WindowManager(const WindowManager&) = delete;

      /// @brief Delete move constructor
      WindowManager(WindowManager&&) = delete;

      /// @brief Update the scene
      void UpdateScene(const tv::FunctionParams& params);

      /// @brief Window resolution
      Vector2 res{};

      /// @brief Window resolution / 2
      Vector2 midRes{};

      /// @brief Window name
      std::string winName{};

      /// @brief Current active scene
      enums::SCENE currentScene{};

      /// @brief Current active scene
      mutable std::mutex resourceLock{};
   };

} // namespace tv
