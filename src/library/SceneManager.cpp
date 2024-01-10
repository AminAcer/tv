
#include "SceneManager.h"
#include "Constants.h"

namespace tv
{
  SceneManager::SceneManager(const enums::SCENE scene, ButtonManager buttonManager, TextManager textManager, RectangleManager rectangleManager)
    :  scene(scene),
       buttonManager(std::move(buttonManager)),
       textManager(std::move(textManager)),
       rectangleManager(std::move(rectangleManager))
  {
  }

  void SceneManager::Update()
  {
    textManager.Draw();
    buttonManager.Draw();
    rectangleManager.Draw();
  }
} // namespace tv
