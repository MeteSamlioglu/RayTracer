cmake_minimum_required(VERSION 2.8)

project(RayTrace)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_SOURCES
            ${PROJECT_SOURCE_DIR}/Objects.cpp
	        ${PROJECT_SOURCE_DIR}/Scene.cpp
            ${PROJECT_SOURCE_DIR}/RGBColor.cpp
            ${PROJECT_SOURCE_DIR}/ImagePlane.cpp
            ${PROJECT_SOURCE_DIR}/LightSource.cpp
            ${PROJECT_SOURCE_DIR}/Camera.cpp
            ${PROJECT_SOURCE_DIR}/IntersectionPoint.cpp
            ${PROJECT_SOURCE_DIR}/Sphere.cpp
            ${PROJECT_SOURCE_DIR}/Vector.cpp
            ${PROJECT_SOURCE_DIR}/Material.cpp
            ${PROJECT_SOURCE_DIR}/Mesh.cpp
            ${PROJECT_SOURCE_DIR}/Ray.cpp
            ${PROJECT_SOURCE_DIR}/main.cpp)
set(PROJECT_HEADERS
            ${PROJECT_SOURCE_DIR}/Objects.hpp
            ${PROJECT_SOURCE_DIR}/Scene.hpp
            ${PROJECT_SOURCE_DIR}/RGBColor.hpp
            ${PROJECT_SOURCE_DIR}/ImagePlane.hpp
            ${PROJECT_SOURCE_DIR}/LightSource.hpp
            ${PROJECT_SOURCE_DIR}/Sphere.hpp
            ${PROJECT_SOURCE_DIR}/IntersectionPoint.hpp
 	        ${PROJECT_SOURCE_DIR}/Vector.hpp
            ${PROJECT_SOURCE_DIR}/Camera.hpp
            ${PROJECT_SOURCE_DIR}/Material.hpp
            ${PROJECT_SOURCE_DIR}/Ray.cpp
            ${PROJECT_SOURCE_DIR}/Mesh.hpp
            )

include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
