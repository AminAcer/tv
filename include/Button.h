#pragma once

#include <math.h>
#include <raylib.h>
#include <string>
#include "Text.h"

namespace tv
{
  class Button
  {
    public:
      /// @brief Constructor
      /// @param position: Button position
      /// @param text: Button text
      /// @param bSize: Button size
      /// @param color: Button color
      Button(Vector2 position, std::string txt, int bSize, Color color)
      : color(color)
      {
        text = Text(txt, position, bSize);
        this->size = Vector2(text.textSize.x + constants::TEXT_BUTTON_SPACING * 2, text.textSize.y + constants::TEXT_BUTTON_SPACING);
        this->position = Vector2(position.x - constants::TEXT_BUTTON_SPACING - text.textSize.x/2, 
            position.y - constants::TEXT_BUTTON_SPACING/2 - text.textSize.y/2);
      }

      /// @brief Delete default constructor
      Button() = delete;

      /// @brief Delete copy constructor
      Button(const Button&) = delete;

      /// @brief Delete move constructor
      Button(Button&&) = delete;

      /// @brief Draw the button
      void Draw()
      {
        DrawRectangleV(position, size, color);
        text.Draw();
      }

      /// @brief Button color
      Color color{};

      /// @brief Button size
      Vector2 size{};

      /// @brief Button position
      Vector2 position{};

      /// @brief Button text
      Text text{};
  };

} // namespace tv
