cmake_minimum_required(VERSION 2.8)
project(PrettyPatterns C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(SDL REQUIRED)
if (${SDL_FOUND} EQUAL "NO")
   message(FATAL_ERROR "'SDL' not found")
endif()
include_directories(${SDL_INCLUDE_DIR})

find_package(M REQUIRED)
if (${HAVE_M} EQUAL "NO")
   message(FATAL_ERROR "'M' not found")
endif()
include_directories(${M_INCLUDES})

aux_source_directory(src SOURCES)

add_executable(PrettyPatterns ${SOURCES})
target_link_libraries(PrettyPatterns ${SDL_LIBRARY})
target_link_libraries(PrettyPatterns ${M_LIBRARIES})
