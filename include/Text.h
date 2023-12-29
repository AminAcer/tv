#pragma once

#include "Constants.h"
#include <raylib.h>

namespace tv
{
   class Text
   {
   public:
      /// @brief Constructor
      /// @param txt: Text being printed
      /// @param pos: Desired position
      /// @param size: Text size
      /// @param color: Text color
      Text(std::string txt, Vector2 pos, float size, Color color = WHITE)
      :  txt(txt),
         size(size),
         color(color)
      {
        textSize = MeasureTextEx(GetFontDefault(), txt.c_str(), size, constants::TEXT_SPACING);
        this->pos = Vector2(pos.x - (textSize.x/2), pos.y - (textSize.y/2));
        std::cout << pos.x << ":" << pos.y << std::endl;
      }

      /// @brief Delete default constructor
      Text() = default;

      /// @brief Delete copy constructor
      //Text(const Text&) = default;

      /// @brief Delete move constructor
      //Text(Text&&) = default;

      void Draw()
      {
         DrawTextEx(GetFontDefault(),
                    txt.c_str(),
                    pos,
                    size,
                    constants::TEXT_SPACING,
                    color);
      }

      /// @brief Actual Text
      std::string txt{};

      /// @brief Text size
      float size{};

      /// @brief Text color
      Color color{};

      /// @brief Actual Text
      Vector2 textSize{};

      /// @brief Text Position
      Vector2 pos{};
   };

} // namespace tv
