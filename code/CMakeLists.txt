cmake_minimum_required(VERSION 3.8)
project(RailEngine)

add_definitions(
  -DTW_STATIC
  -DTW_NO_LIB_PRAGMA
  -DTW_NO_DIRECT3D
  -DGLEW_STATIC
)

# Shared source collection
include_directories(src/)
aux_source_directory(src SOURCE)
aux_source_directory(external SOURCE)

IF(WIN32)
  find_package(OpenGL REQUIRED)

  include_directories(C:/glfw-3.3.9.bin.WIN64/include/)
  include_directories(C:/glew-2.1.0/include/)
  include_directories(C:/glew-2.1.0/include/GL/)
  include_directories(C:/GLM_0.9.9.8/g-truc-glm-bf71a83/)

  link_directories(C:/glew-2.1.0/lib/Release/x64/)
  link_directories(C:/glfw-3.3.9.bin.WIN64/lib-vc2019/)

  add_executable(${PROJECT_NAME} main.cpp ${SOURCE})
  target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} glew32s glfw3)

ELSE()
  set(CMAKE_BUILD_TYPE Debug)
  set(CMAKE_CXX_STANDARD 11)

  find_package(OpenGL REQUIRED COMPONENTS OpenGL)
  find_package(GLEW REQUIRED)
  find_package(glfw3 REQUIRED
      HINTS /encs/pkg/glfw-3.4/root
  )

  add_executable(${PROJECT_NAME} main.cpp ${SOURCE})
  target_link_libraries(${PROJECT_NAME} OpenGL::GL GLEW::glew glfw)

ENDIF()