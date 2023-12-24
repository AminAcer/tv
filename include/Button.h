#pragma once

#include "raylib.h"

namespace tv
{
   class Button
   {
   public:
      /// @brief Constructor
      /// @param position: Rectangle position
      /// @param size: Rectangle size
      /// @param color: Rectangle color
      Button(Vector2 position, Vector2 size, Color color)
      :  size(size),
         color(color),
         position(Vector2(position.x - (size.x / 2), position.y - (size.y / 2)))
      {
      }
      
      /// @brief Delete default constructor
      Button() = delete;

      /// @brief Delete copy constructor
      Button(const Button&) = delete;

      /// @brief Delete move constructor
      Button(Button&&) = delete;

      void Draw()
      {
         DrawRectangleV(position, size, color);
      }

      /// @brief Rectangle size
      Vector2 size{};
      
      /// @brief Rectangle color
      Color color{};

      /// @brief Rectangle position
      Vector2 position{};
   };

} // namespace tv
