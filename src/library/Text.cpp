
#include "Text.h"
#include "Constants.h"

namespace tv
{
  Text::Text(std::string txt, Vector2 pos, float size, Color color)
  :  txt(txt),
     size(size),
     color(color)
  {
    textSize = MeasureTextEx(GetFontDefault(), txt.c_str(), size, constants::TEXT_SPACING);
    this->pos = Vector2{pos.x - (textSize.x/2), pos.y - (textSize.y/2)};
  }
  
  void Text::Draw()
  {
    DrawTextEx(GetFontDefault(),
        txt.c_str(),
        pos,
        size,
        constants::TEXT_SPACING,
        color);
  }
} // namespace tv
