
#include "CursorManager.h"
#include "Logger.h"

namespace tv
{
  std::optional<Vector2> CursorManager::CheckClick()
  {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      auto pos = GetMousePosition();
      LOG_INFO("Mouse clicked (%d, %d)", pos.x , pos.y);

      return pos;
    }

    return std::nullopt;
  }
} // namespace tv
