
#include "Button.h"
#include "Constants.h"

namespace tv
{
  Button::Button(Vector2 position, std::string txt, int bSize, Color color, tv::FunctionParams params, const std::function<void(const tv::FunctionParams&)>& clickFn)
  : color(color),
    params(std::move(params)),
    clickCallback(clickFn)
  {
    text = Text(txt, position, bSize);
    this->size = Vector2{text.textSize.x + constants::TEXT_BUTTON_SPACING * 2, text.textSize.y + constants::TEXT_BUTTON_SPACING};
    this->position = Vector2{position.x - constants::TEXT_BUTTON_SPACING - text.textSize.x/2, 
        position.y - constants::TEXT_BUTTON_SPACING/2 - text.textSize.y/2};
  }

  Button::Button(Vector2 position, std::string txt, int bSize, Color color, const std::function<void(const tv::FunctionParams&)>& clickFn)
  : color(color),
    clickCallback(clickFn)
  {
    text = Text(txt, position, bSize);
    this->size = Vector2{text.textSize.x + constants::TEXT_BUTTON_SPACING * 2, text.textSize.y + constants::TEXT_BUTTON_SPACING};
    this->position = Vector2{position.x - constants::TEXT_BUTTON_SPACING - text.textSize.x/2, 
        position.y - constants::TEXT_BUTTON_SPACING/2 - text.textSize.y/2};
  }

  Button::Button(Vector2 position, std::string txt, int bSize, Color color)
  : color(color)
  {
    text = Text(txt, position, bSize);
    this->size = Vector2{text.textSize.x + constants::TEXT_BUTTON_SPACING * 2, text.textSize.y + constants::TEXT_BUTTON_SPACING};
    this->position = Vector2{position.x - constants::TEXT_BUTTON_SPACING - text.textSize.x/2, 
        position.y - constants::TEXT_BUTTON_SPACING/2 - text.textSize.y/2};
  }

  Button& Button::operator=(Button&& other)
  {
    if(this != &other)
    {
      color = std::move(other.color);
      size = std::move(other.size);
      position = std::move(other.position);
      cursor = std::move(other.cursor);
      text = std::move(other.text);
    }
    return *this;
  }

  Button Button::operator=(const Button& other)
  {
    if(this != &other)
    {
      color = other.color;
      size = other.size;
      position = other.position;
      cursor = other.cursor;
      text = other.text;
    }
    return *this;
  }

  void Button::Draw()
  {
    CheckClick();
    DrawRectangleV(position, size, color);
    text.Draw();
  }

  void Button::CheckClick()
  {
    auto cursor = GetMousePosition();
    if(cursor.x >= position.x && cursor.x <= position.x + size.x &&
       cursor.y >= position.y && cursor.y <= position.y + size.y)
    {
      color = constants::GRAY_2;
      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      {
        clickCallback(params);
      }
    }
    else
    {
      color = constants::GRAY_4;
    }
  }
} // namespace tv
