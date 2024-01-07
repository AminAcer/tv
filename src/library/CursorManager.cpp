
#include "CursorManager.h"

namespace tv
{
  std::optional<Vector2> CursorManager::CheckClick()
  {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      auto pos = GetMousePosition();
      std::cout << "Mouse clicked (" << pos.x << ", " << pos.y << ")\n";

      return pos;
    }

    return std::nullopt;
  }
} // namespace tv
