
#include "ButtonManager.h"
#include "Constants.h"

namespace tv
{
  ButtonManager::ButtonManager(const ButtonManager& other)
  {
    std::unique_lock<std::mutex> rlck(other.rLock);
    buttons = other.buttons;
  }
  
  ButtonManager::ButtonManager(ButtonManager&& other)
  {
    std::unique_lock<std::mutex> llck(rLock, std::defer_lock);
    std::unique_lock<std::mutex> rlck(other.rLock, std::defer_lock);
    std::lock(llck, rlck);
    buttons = std::move(other.buttons);
  }
  
  void ButtonManager::Update()
  {
    std::scoped_lock<std::mutex> lock{rLock};
    for(auto& button : buttons)
    {
      button.Draw();
    }
  }

  void ButtonManager::AddButton(tv::Button button)
  {
    std::scoped_lock<std::mutex> lock{rLock};
    buttons.push_back(std::move(button));
  }
} // namespace tv
