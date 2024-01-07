#pragma once

#include <raylib.h>
#include <iostream>

namespace constants
{
   // Performance
   const int FPS = 60;

   // Colors
   const Color MAIN_GRAY = Color{114,115,115, 255};
   const Color GRAY_1 = Color{214,214,214,255};
   const Color GRAY_2 = Color{145,145,145,255};
   const Color GRAY_3 = Color{91,91,91,255};
   const Color GRAY_4 = Color{63,63,63,255};

   // Text
   const int TEXT_SPACING = 10.0;
   const int TEXT_BUTTON_SPACING = 20.0;
} // namespace constants

namespace enums
{
   enum class SCENE : uint8_t
   {
     MENU,
     MAIN,
     PAUSE
   };
} // namespace enums
