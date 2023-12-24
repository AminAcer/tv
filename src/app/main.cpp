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

   auto b1 = tv::Button(Vector2(GetScreenWidth()/2,GetScreenHeight()/2), Vector2(100,50), Color(220,220,220,255));
   while(!WindowShouldClose())
   {
     
      BeginDrawing();
      ClearBackground(constants::MAIN_GRAY);
      
      b1.Draw();
      EndDrawing();
   }

   CloseWindow();

   return 0;
}
