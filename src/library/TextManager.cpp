
#include "TextManager.h"
#include "Constants.h"

namespace tv
{
  TextManager::TextManager(const TextManager& other)
  {
    std::unique_lock<std::mutex> rlck(other.rLock);
    texts = other.texts;
  }
  
  TextManager::TextManager(TextManager&& other)
  {
    std::unique_lock<std::mutex> llck(rLock, std::defer_lock);
    std::unique_lock<std::mutex> rlck(other.rLock, std::defer_lock);
    std::lock(llck, rlck);
    texts = std::move(other.texts);
  }
  
  void TextManager::Draw()
  {
    std::scoped_lock<std::mutex> lock{rLock};
    for(auto& text : texts)
    {
      text.Draw();
    }
  }

  void TextManager::AddText(tv::Text text)
  {
    std::scoped_lock<std::mutex> lock{rLock};
    texts.push_back(std::move(text));
  }
} // namespace tv
