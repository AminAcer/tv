#pragma once

#include <raylib.h>
#include <iostream>

#define MONITOR 0

namespace tv
{
   class WindowManager
   {
   public:
      /// @brief Constructor
      /// @param windowWidth: Window width
      /// @param windowHeight: Window height
      /// @param windowName: Window name
      WindowManager(int windowWidth, int windowHeight, std::string windowName)
      :  width(windowWidth),
         height(windowHeight),
         mid_x(windowWidth/2),
         mid_y(windowHeight/2),
         winName(windowName)
      {
         ::InitWindow(width, height, winName.c_str());
         //::ToggleFullscreen();
         ::SetWindowMonitor(MONITOR);
         ::SetWindowState(FLAG_VSYNC_HINT);
      }

      /// @brief Delete default constructor
      WindowManager() = delete;

      /// @brief Delete copy constructor
      WindowManager(const WindowManager&) = delete;

      /// @brief Delete move constructor
      WindowManager(WindowManager&&) = delete;

      /// @brief Window width
      int width{};

      /// @brief Window height
      int height{};

      /// @brief Window width / 2
      int mid_x{};

      /// @brief Window height / 2
      int mid_y{};

      /// @brief Window name
      std::string winName{};
   };

} // namespace tv
