cmake_minimum_required(VERSION 3.29.3)
project(tutorial_game)

add_executable(${PROJECT_NAME} src/main.cpp)

# Download all submodules
find_package(Git QUIET)
if (GIT_FOUND and EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if (GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if (NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules.")
    endif()
  endif()
endif()

# Check all the submodules
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/external_modules/glfw/CMakeLists.txt")
  message(FATAL_ERROR "The glfw submodules were not downloaded. GIT_SUBMODULE was turned off or failed. Please update submodules.")
endif()

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
