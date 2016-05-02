cmake_minimum_required(VERSION 3.0)
project(statistics)

if(MSVC)
	# for ChaiScript
	add_definitions(/bigobj)
endif()

mark_as_advanced (CMAKE_CONFIGURATION_TYPES)
mark_as_advanced (CMAKE_INSTALL_PREFIX)

file(GLOB_RECURSE srcs statistics/*.cpp statistics/*.h)

include_directories(../ascent-statistics)

include_directories(../ascent)
include_directories(../ascent/eigen)
include_directories(../ascent/ChaiScript/include)

link_directories(../ascent/build)

add_library(${PROJECT_NAME} STATIC ${srcs})

add_subdirectory(examples)