#include <iostream>
#include <unordered_map>
#include <memory>
#include "WindowManager.h"
#include "Constants.h"
#include "SceneManager.h"

int main()
{
   // Window init
   tv::WindowManager window(Vector2(1280, 720), "tv", enums::SCENE::MENU); 

   // FPS
   SetTargetFPS(constants::FPS);

   // Menu Scene ---------
   auto buttonManager = tv::ButtonManager();
   auto b1 = tv::Button(Vector2(window.midRes), "Start", 35, constants::GRAY_4, tv::FunctionParams(enums::SCENE::MAIN), [&window](const tv::FunctionParams& params) { window.UpdateScene(params); });
   auto b2 = tv::Button(Vector2(window.midRes.x,window.midRes.y + 75), "Quit", 35, constants::GRAY_4);
   buttonManager.AddButton(b1);
   buttonManager.AddButton(b2);

   auto textManager = tv::TextManager();
   auto title = tv::Text("TV", Vector2(window.midRes.x, window.midRes.y - 250), 100);
   textManager.AddText(title);

   auto menuScene = std::make_unique<tv::SceneManager>(enums::SCENE::MENU, buttonManager, textManager);

   // Main Scene ----------
   auto buttonManager2 = tv::ButtonManager();

   auto b22 = tv::Button(Vector2(window.midRes.x - 233,window.midRes.y + 75), "Menu", 35, constants::GRAY_4, tv::FunctionParams(enums::SCENE::MENU), [&window](const tv::FunctionParams& params) { window.UpdateScene(params); });
   buttonManager2.AddButton(b22);

   auto textManager2 = tv::TextManager();
   auto title2 = tv::Text("Main", Vector2(window.midRes.x, window.midRes.y - 300), 100);
   textManager2.AddText(title2);

   auto mainScene = std::make_unique<tv::SceneManager>(enums::SCENE::MENU, buttonManager2, textManager2);

   std::unordered_map<enums::SCENE, std::unique_ptr<tv::SceneManager>> scenes{};

   scenes.try_emplace(enums::SCENE::MENU, std::move(menuScene));
   scenes.try_emplace(enums::SCENE::MAIN, std::move(mainScene));

   while(!WindowShouldClose())
   {
     ClearBackground(constants::MAIN_GRAY);
     BeginDrawing();


      // Draw scene
      scenes.at(window.currentScene)->Update();

     EndDrawing();
   }

   CloseWindow();

   return 0;
}
