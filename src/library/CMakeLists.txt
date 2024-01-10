target_compile_features(${PROJECT_NAME}-launch PRIVATE cxx_std_20)
find_package(raylib REQUIRED)

set(INCLUDE_DIRS
   ${CMAKE_SOURCE_DIR}/include/
)

set(SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/src/library/Button.cpp
  ${CMAKE_SOURCE_DIR}/src/library/Rectangle.cpp
  ${CMAKE_SOURCE_DIR}/src/library/ButtonManager.cpp
  ${CMAKE_SOURCE_DIR}/src/library/CMakeLists.txt
  ${CMAKE_SOURCE_DIR}/src/library/CursorManager.cpp
  ${CMAKE_SOURCE_DIR}/src/library/SceneManager.cpp
  ${CMAKE_SOURCE_DIR}/src/library/Text.cpp
  ${CMAKE_SOURCE_DIR}/src/library/TextManager.cpp
  ${CMAKE_SOURCE_DIR}/src/library/WindowManager.cpp
  ${CMAKE_SOURCE_DIR}/src/library/Rectangle.cpp
  ${CMAKE_SOURCE_DIR}/src/library/RectangleManager.cpp
)

add_library(${PROJECT_NAME}-lib ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}-lib PUBLIC ${INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}-lib PUBLIC raylib)
