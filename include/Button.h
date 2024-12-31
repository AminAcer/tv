#pragma once

#include "FunctionParams.h"
#include "Logger.h"
#include "Text.h"
#include <functional>
#include <math.h>
#include <raylib.h>
#include <string>

namespace tv {
// Defautl function if one is not provided for the button
const std::function<void(const tv::FunctionParams &)> defaultClickFunction =
    [](const tv::FunctionParams &) { LOG_INFO("Function Not Impl"); };

class Button {
public:
  /// @brief Constructor
  /// @param position: Button position
  /// @param text: Button text
  /// @param bSize: Button size
  /// @param color: Button color
  /// @param params: Function params for the button
  /// @param clickFn: Function to call when the button is clicked
  Button(Vector2 position, std::string txt, int bSize, Color color,
         tv::FunctionParams params,
         const std::function<void(const tv::FunctionParams &)> &clickFn);

  /// @brief Constructor
  /// @param position: Button position
  /// @param text: Button text
  /// @param bSize: Button size
  /// @param color: Button color
  /// @param clickFn: Function to call when the button is clicked
  Button(Vector2 position, std::string txt, int bSize, Color color,
         const std::function<void(const tv::FunctionParams &)> &clickFn);

  /// @brief Constructor
  /// @param position: Button position
  /// @param text: Button text
  /// @param bSize: Button size
  /// @param color: Button color
  Button(Vector2 position, std::string txt, int bSize, Color color);

  /// @brief Delete default constructor
  Button() = delete;

  /// @brief Delete copy constructor
  Button(const Button &) = default;

  /// @brief Delete move constructor
  Button(Button &&other) = default;

  /// @brief Move assignment constructor
  Button &operator=(Button &&other);

  /// @brief Move assignment constructor
  Button operator=(const Button &other);

  /// @brief Draw the button
  void Draw();

  /// @brief Check if mouse is hovering button
  void CheckClick();

  /// @brief Button color
  Color color{};

  /// @brief Button size
  Vector2 size{};

  /// @brief Button position
  Vector2 position{};

  /// @brief Cursor position
  Vector2 cursor{};

  /// @brief Button text
  Text text{};

  /// @brief Button text
  tv::FunctionParams params{};

  /// @brief Function called on click
  std::function<void(const tv::FunctionParams &)> clickCallback{
      defaultClickFunction};
};

} // namespace tv
