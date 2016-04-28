
include_directories(
  ${CMAKE_SOURCE_DIR}/include
)

add_executable(Lighting main.cpp)

set(EXTRA_LIBS
    ${CMAKE_SOURCE_DIR}/lib/Windows/OpenGL32.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/freetype.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/ftgld.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/glfw3d.lib
    ${CMAKE_SOURCE_DIR}/lib/Windows/OpenAL32.lib
)

target_link_libraries(Lighting ${EXTRA_LIBS})
