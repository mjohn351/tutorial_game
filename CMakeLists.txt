cmake_minimum_required(VERSION 3.29.3)
project(tutorial_game)

add_executable(${PROJECT_NAME} src/main.cpp)



add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME}
  PUBLIC external/glfw/include/
  PUBLIC external/glfw/deps/
  PUBLIC include
)
target_link_directories(${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/../lib
  PUBLIC Header Files/
)
target_link_libraries(${PROJECT_NAME} glfw)
