
#include "Rectangle.h"
#include "Constants.h"

namespace tv
{
  Rectangle::Rectangle(Vector2 position, Vector2 size, Color color)
  : color(color),
    size(size)
  {
    this->position = Vector2{position.x - size.x/2, position.y - size.y/2};
  }

  Rectangle& Rectangle::operator=(Rectangle&& other)
  {
    if(this != &other)
    {
      color = std::move(other.color);
      size = std::move(other.size);
      position = std::move(other.position);
    }
    return *this;
  }

  Rectangle Rectangle::operator=(const Rectangle& other)
  {
    if(this != &other)
    {
      color = other.color;
      size = other.size;
      position = other.position;
    }
    return *this;
  }

  void Rectangle::Draw()
  {
    DrawRectangleV(position, size, color);
  }
} // namespace tv
