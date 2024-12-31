#pragma once

#include "ButtonManager.h"
#include "CursorManager.h"
#include "RectangleManager.h"
#include "TextManager.h"
#include <iostream>
#include <raylib.h>

#define MONITOR 0

namespace tv {
class SceneManager {
public:
  /// @brief Constructor
  SceneManager(const enums::SCENE scene, ButtonManager buttonManager = {},
               TextManager textManager = {},
               RectangleManager rectangleManager = {});

  /// @brief Delete default constructor
  SceneManager() = delete;

  /// @brief Delete copy constructor
  SceneManager(const SceneManager &) = delete;

  /// @brief Delete move constructor
  SceneManager(SceneManager &&) = delete;

  /// @bried Update this object each frame
  void Update();

  /// @brief Scene for all of these objects
  enums::SCENE scene{};

  /// @brief Button manager
  ButtonManager buttonManager{};

  /// @brief Text manager
  TextManager textManager{};

  /// @brief Rectangle manager
  RectangleManager rectangleManager{};

  /// @brief Cursor Manager
  CursorManager cursorManager{};
};

} // namespace tv
