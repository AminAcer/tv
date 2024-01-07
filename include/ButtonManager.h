#pragma once

#include <raylib.h>
#include <string>
#include <vector>
#include <mutex>
#include "Button.h"
#include "Text.h"

namespace tv
{
  class ButtonManager
  {
    public:
      /// @brief Constructor
      ButtonManager() = default;

      /// @brief Delete copy constructor
      ButtonManager(const ButtonManager& other);

      /// @brief Delete move constructor
      ButtonManager(ButtonManager&& other);

      /// @brief Update the button
      void Update();

      /// @brief Adds a button
      void AddButton(tv::Button button);

    private:
      /// @brief All buttons owned by this manager
      std::vector<tv::Button> buttons{};

      /// @brief Mutex for shared resources
      mutable std::mutex rLock{};
  };

} // namespace tv
