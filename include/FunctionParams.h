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

      /// @brief Delete copy constructor
      FunctionParams(const FunctionParams&) = delete;

      /// @brief Delete move constructor
      FunctionParams(FunctionParams&&) = delete;

      /// @brief Scene
      enums::SCENE scene{};
   };

} // namespace tv
