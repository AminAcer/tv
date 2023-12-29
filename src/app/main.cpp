#include <iostream>
#include "WindowManager.h"
#include "Constants.h"
#include "Button.h"

int main()
{
   // Window init
   tv::WindowManager window(1280, 720, "tv"); 

   // FPS
   SetTargetFPS(constants::FPS);

   auto b1 = tv::Button(Vector2(window.mid_x,window.mid_y), "Start", 35, constants::GRAY_4);
   auto b2 = tv::Button(Vector2(window.mid_x,window.mid_y + 75), "Quit", 35, constants::GRAY_4);
   auto title = tv::Text("TV", Vector2(window.mid_x, window.mid_y - 250), 100);
   while(!WindowShouldClose())
   {
     ClearBackground(constants::MAIN_GRAY);
     BeginDrawing();

     // Draw buttons
     b1.Draw();
     b2.Draw();

     // Title
     title.Draw();

     EndDrawing();
   }

   CloseWindow();

   return 0;
}
