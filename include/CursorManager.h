#pragma once

#include "Constants.h"
#include <math.h>
#include <optional>
#include <raylib.h>

namespace tv {
class CursorManager {
public:
  /// @brief Constructor
  CursorManager() = default;

  /// @brief Delete copy constructor
  CursorManager(const CursorManager &) = delete;

  /// @brief Delete move constructor
  CursorManager(CursorManager &&) = delete;

  /// @brief Check if mouse was clicked and return position if so
  /// @return Vector2 of cursor position if clicked
  std::optional<Vector2> CheckClick();
};

} // namespace tv
