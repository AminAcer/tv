
#include "WindowManager.h"
#include "Constants.h"

namespace tv
{
  WindowManager::WindowManager(Vector2 res, std::string windowName, enums::SCENE initScene)
    :  res(res),
       winName(windowName)
  {
    InitWindow(res.x, res.y, winName.c_str());
    //::ToggleFullscreen();
    SetWindowMonitor(MONITOR);
    SetWindowState(FLAG_VSYNC_HINT);

    midRes = Vector2{res.x/2, res.y/2};
  }

  void WindowManager::UpdateScene(const tv::FunctionParams& params)
  {
    std::scoped_lock<std::mutex> lock{resourceLock};
    std::cout << "Updating scene to: " << params.SceneToString() << std::endl;
    currentScene = params.scene;
  }
} // namespace tv
