#pragma once

#include "Button.h"
#include "Text.h"
#include <mutex>
#include <raylib.h>
#include <string>
#include <vector>

namespace tv {
class ButtonManager {
public:
  /// @brief Constructor
  ButtonManager() = default;

  /// @brief Delete copy constructor
  ButtonManager(const ButtonManager &other);

  /// @brief Delete move constructor
  ButtonManager(ButtonManager &&other);

  /// @brief Draw the button
  void Draw();

  /// @brief Adds a button
  void AddButton(tv::Button button);

private:
  /// @brief All buttons owned by this manager
  std::vector<tv::Button> buttons{};

  /// @brief Mutex for shared resources
  mutable std::mutex rLock{};
};

} // namespace tv
