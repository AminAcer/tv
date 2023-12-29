target_compile_features(${PROJECT_NAME}-launch PRIVATE cxx_std_20)

set(INCLUDE_DIRS
   ${CMAKE_SOURCE_DIR}/include/
)

set(SOURCE_FILES
  ${CMAKE_SOURCE_DIR}/src/library/Button.cpp
)

add_library(${PROJECT_NAME}-lib ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}-lib PUBLIC ${INCLUDE_DIRS})
