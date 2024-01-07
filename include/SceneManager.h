#pragma once

#include <raylib.h>
#include <iostream>
#include "ButtonManager.h"
#include "TextManager.h"
#include "CursorManager.h"

#define MONITOR 0

namespace tv
{
   class SceneManager
   {
   public:
      /// @brief Constructor
      /// @param InitScene: Managed scene
      SceneManager(const enums::SCENE scene, tv::ButtonManager buttonManager, tv::TextManager textManager);

      /// @brief Delete default constructor
      SceneManager() = delete;

      /// @brief Delete copy constructor
      SceneManager(const SceneManager&) = delete;

      /// @brief Delete move constructor
      SceneManager(SceneManager&&) = delete;

      /// @bried Update this object each frame
      void Update();

      /// @brief Scene for all of these objects 
      enums::SCENE scene{};

      /// @brief Button manager
      tv::ButtonManager buttonManager{};
      
      /// @brief Text manager
      tv::TextManager textManager{};
   
      /// @brief Cursor Manager
      tv::CursorManager cursorManager{};
   };

} // namespace tv
