#pragma once

#include "Text.h"
#include <mutex>
#include <raylib.h>
#include <string>
#include <vector>

namespace tv {
class TextManager {
public:
  /// @brief Constructor
  TextManager() = default;

  /// @brief Delete copy constructor
  TextManager(const TextManager &other);

  /// @brief Delete move constructor
  TextManager(TextManager &&other);

  /// @brief Update the text
  void Draw();

  /// @brief Adds a text
  void AddText(tv::Text text);

private:
  /// @brief All texts owned by this manager
  std::vector<tv::Text> texts{};

  /// @brief Mutex for shared resources
  mutable std::mutex rLock{};
};

} // namespace tv
