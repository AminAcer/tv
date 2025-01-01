#include <iostream>
#include <unordered_map>
#include <memory>
#include <Logger.h>
#include <WindowManager.h>
#include <Constants.h>
#include <SceneManager.h>

// Constants
const int FPS = 60;


int main()
{
   // Window init
   tv::WindowManager window(Vector2{1280, 720}, "tv", enums::SCENE::MENU); 

   // FPS
   SetTargetFPS(FPS);

   // Menu Scene ---------
   auto buttonManager = tv::ButtonManager();
   auto startButton = tv::Button(Vector2{window.midRes}, "Start", 35, constants::GRAY_4, tv::FunctionParams(enums::SCENE::MAIN), [&window](const tv::FunctionParams& params) { window.UpdateScene(params); });
   auto quitButton = tv::Button(Vector2{window.midRes.x,window.midRes.y + 75}, "Quit", 35, constants::GRAY_4, [&window](const tv::FunctionParams& params) { window.CloseWindow(); });

   buttonManager.AddButton(startButton);
   buttonManager.AddButton(quitButton);

   auto textManager = tv::TextManager();
   auto title = tv::Text("TV", Vector2{window.midRes.x, window.midRes.y - 250}, 100);
   textManager.AddText(title);

   auto menuScene = std::make_unique<tv::SceneManager>(enums::SCENE::MENU, buttonManager, textManager);

   // Main Scene ----------
   auto buttonManager2 = tv::ButtonManager();

   auto menuButton = tv::Button(Vector2{65, window.res.y - 28}, "Menu", 20, constants::GRAY_4, tv::FunctionParams(enums::SCENE::MENU), [&window](const tv::FunctionParams& params) { window.UpdateScene(params); });
   auto blendButton = tv::Button(Vector2{90, 40}, "Shuffle", 20, constants::GRAY_4);
   buttonManager2.AddButton(menuButton);
   buttonManager2.AddButton(blendButton);

   auto textManager2 = tv::TextManager();
   auto services = tv::Text("Status", Vector2{window.res.x - 85, 25}, 22);
   auto tv = tv::Text("TV", Vector2{window.res.x - 85, 60}, 20, RED);
   auto blender = tv::Text("Blender", Vector2{window.res.x - 85, 85}, 20, RED);
   auto dvr = tv::Text("DVR", Vector2{window.res.x - 85, 110}, 20, RED);
   auto cams = tv::Text("Cameras", Vector2{window.res.x - 85, 135}, 20, RED);
   auto closet = tv::Text("Closet", Vector2{window.res.x - 85, 160}, 20, RED);
   auto sorter = tv::Text("Sorter", Vector2{window.res.x - 85, 185}, 20, RED);
   textManager2.AddText(services);
   textManager2.AddText(tv);
   textManager2.AddText(blender);
   textManager2.AddText(dvr);
   textManager2.AddText(cams);
   textManager2.AddText(closet);
   textManager2.AddText(sorter);

   auto recManager = tv::RectangleManager();
   auto r1 = tv::Rectangle(Vector2{window.res.x - 85, 40}, Vector2{160, 4}, BLACK);
   recManager.AddRectangle(r1);

   auto mainScene = std::make_unique<tv::SceneManager>(enums::SCENE::MENU, buttonManager2, textManager2, recManager);

   std::unordered_map<enums::SCENE, std::unique_ptr<tv::SceneManager>> scenes{};

   scenes.try_emplace(enums::SCENE::MENU, std::move(menuScene));
   scenes.try_emplace(enums::SCENE::MAIN, std::move(mainScene));

   while(!WindowShouldClose() && window.isActive)
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
