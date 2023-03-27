# CMake entry point
cmake_minimum_required (VERSION 3.12)
project (SiroGen83)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")
	# -Wall -Werror -pedantic 
	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3.8/include/
	external/glad-3.3/include/
	external/glm-0.9.9.8/
	.
)

link_directories( # g++ -Lpath/to/library
)

set(ALL_GRAPHICS_LIBS
	glfw
	SiroGen83
)

# SiroGen83 (libSiroGen83.a)
add_library(SiroGen83 # ar rcs libSiroGen83.a
	external/glad-3.3/src/glad.c
	SiroGen83/core.h
	SiroGen83/core.cpp
	SiroGen83/input.h
	SiroGen83/input.cpp
	SiroGen83/scene.h
	SiroGen83/entity.h
	SiroGen83/entity.cpp
	SiroGen83/tile.h
	SiroGen83/renderer.h
	SiroGen83/renderer.cpp
	SiroGen83/camera.h
	SiroGen83/camera.cpp
	SiroGen83/vector2.h
	SiroGen83/sprite.h
)

# Test
add_executable(Test # g++ Test/main.cpp -o Test
	Test/main.cpp
	Test/world1.cpp
	Test/world1.h
)
target_link_libraries(Test # g++ -lSiroGen83
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(Test
		${ALL_GRAPHICS_LIBS}
	)


# BurgerBoss
add_executable(BurgerBoss # g++ BurgerBoss/main.cpp -o BurgerBoss
	BurgerBoss/main.cpp
	BurgerBoss/world1.cpp
	BurgerBoss/world1.h
	BurgerBoss/spritefactory.h
	BurgerBoss/character.cpp
	BurgerBoss/character.h
	BurgerBoss/player.cpp
	BurgerBoss/player.h
	BurgerBoss/entityspawner.cpp
	BurgerBoss/entityspawner.h
)
target_link_libraries(BurgerBoss # g++ -lSiroGen83
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(BurgerBoss
		${ALL_GRAPHICS_LIBS}
	)
