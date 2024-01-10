#pragma once

#include <raylib.h>
#include <string>
#include <vector>
#include <mutex>
#include "Rectangle.h"

namespace tv
{
  class RectangleManager
  {
    public:
      /// @brief Constructor
      RectangleManager() = default;

      /// @brief Delete copy constructor
      RectangleManager(const RectangleManager& other);

      /// @brief Delete move constructor
      RectangleManager(RectangleManager&& other);

      /// @brief Update the Rectangle
      void Draw();
      
      /// @brief Adds a Rectangle
      void AddRectangle(tv::Rectangle rect);

    private:
      /// @brief All rects owned by this manager
      std::vector<tv::Rectangle> rects{};

      /// @brief Mutex for shared resources
      mutable std::mutex rLock{};
  };

} // namespace tv
