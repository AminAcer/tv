#pragma once

#include <raylib.h>
#include "Constants.h"

namespace tv
{
   class FunctionParams
   {
   public:
      /// @brief Constructor
      FunctionParams(enums::SCENE scene) : scene(scene)
      {
      }

      /// @brief Default constructor
      FunctionParams() = default;

      /// @brief Delete copy constructor
      FunctionParams(const FunctionParams& other)
      {
        scene = other.scene;
      }

      /// @brief Delete move constructor
      FunctionParams(FunctionParams&& other)
      {
        scene = std::move(other.scene);
      }

      std::string SceneToString() const
      {
        auto out = std::string("ERROR SCENE");

        switch(scene)
        {
          case enums::SCENE::MAIN:
            out = "MAIN";
            break;
          case enums::SCENE::MENU:
            out = "MENU";
            break;
          case enums::SCENE::PAUSE:
            out = "PAUSE";
            break;
          default:
            break;
        }

        return out;
      }

      /// @brief Scene
      enums::SCENE scene{};
   };

} // namespace tv
