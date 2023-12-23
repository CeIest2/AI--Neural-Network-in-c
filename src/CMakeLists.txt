cmake_minimum_required(VERSION 3.10)
project(OpenGLTest C)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(OpenGLTest fichier_open_gl/main_opgl.c)
target_link_libraries(OpenGLTest ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
