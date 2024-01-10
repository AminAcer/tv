
#include "RectangleManager.h"
#include "Constants.h"

namespace tv
{
  RectangleManager::RectangleManager(const RectangleManager& other)
  {
    std::unique_lock<std::mutex> rlck(other.rLock);
    rects = other.rects;
  }
  
  RectangleManager::RectangleManager(RectangleManager&& other)
  {
    std::unique_lock<std::mutex> llck(rLock, std::defer_lock);
    std::unique_lock<std::mutex> rlck(other.rLock, std::defer_lock);
    std::lock(llck, rlck);
    rects = std::move(other.rects);
  }
  
  void RectangleManager::Draw()
  {
    std::scoped_lock<std::mutex> lock{rLock};
    for(auto& rect: rects)
    {
      rect.Draw();
    }
  }

  void RectangleManager::AddRectangle(tv::Rectangle rect)
  {
    std::scoped_lock<std::mutex> lock{rLock};
    rects.push_back(std::move(rect));
  }
} // namespace tv
