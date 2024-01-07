
#include "SceneManager.h"
#include "Constants.h"

namespace tv
{
  SceneManager::SceneManager(const enums::SCENE scene, tv::ButtonManager buttonManager, tv::TextManager textManager)
    :  scene(scene),
       buttonManager(std::move(buttonManager)),
       textManager(std::move(textManager))
  {
  }

  void SceneManager::Update()
  {
    textManager.Draw();
    buttonManager.Update();
  }
} // namespace tv
