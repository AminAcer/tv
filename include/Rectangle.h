#pragma once

#include <functional>
#include <math.h>
#include <raylib.h>

namespace tv {
class Rectangle {
public:
  /// @brief Constructor
  /// @param position: Rectangle position
  /// @param size: Rectangle size
  /// @param color: Rectangle color
  Rectangle(Vector2 position, Vector2 size, Color color);

  /// @brief Delete default constructor
  Rectangle() = delete;

  /// @brief Delete copy constructor
  Rectangle(const Rectangle &) = default;

  /// @brief Delete move constructor
  Rectangle(Rectangle &&other) = default;

  /// @brief Move assignment constructor
  Rectangle &operator=(Rectangle &&other);

  /// @brief Move assignment constructor
  Rectangle operator=(const Rectangle &other);

  /// @brief Draw the Rectangle
  void Draw();

  /// @brief Rectangle color
  Color color{};

  /// @brief Rectangle size
  Vector2 size{};

  /// @brief Rectangle position
  Vector2 position{};
};

} // namespace tv
