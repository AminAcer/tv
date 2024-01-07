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
      Text(std::string txt, Vector2 pos, float size, Color color = WHITE);

      /// @brief Delete default constructor
      Text() = default;

      /// @brief Draw test
      void Draw();

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
