cmake_minimum_required(VERSION 2.8)
project(pointer-example)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -g -O0")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)




# Try to see if user has OpenCV installed
# if yes, default callback will display the image
find_package( OpenCV QUIET )
if (OpenCV_FOUND)
    message( "\n${PROJECT_NAME}...")
    message( STATUS "Found OpenCV installed in the system, will use it to display image in AdvancedSensing APIs")
    message( STATUS " - Includes: ${OpenCV_INCLUDE_DIRS}")
    message( STATUS " - Libraries: ${OpenCV_LIBRARIES}")
    add_definitions(-DOPEN_CV_INSTALLED)
else()
    message( STATUS "Did not find OpenCV in the system, image data is inside RecvContainer as raw data")
endif ()

include_directories(${PROJECT_NAME} ${OpenCV_INCLUDE_DIRS})


#include_directories(/usr/local/include/djiosdk-core)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hal)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/osal)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/quad_prog)


FILE(GLOB SOURCE_FILES *.hpp *.cpp)
#          ${CMAKE_CURRENT_SOURCE_DIR}/common/dji_linux_environment.cpp
#          ${CMAKE_CURRENT_SOURCE_DIR}/common/dji_linux_helpers.cpp
#          ${CMAKE_CURRENT_SOURCE_DIR}/hal/*.c
#          ${CMAKE_CURRENT_SOURCE_DIR}/osal/*.c
#          ${CMAKE_CURRENT_SOURCE_DIR}/quad_prog/*.cpp
#          )



add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} )


if (OpenCV_FOUND)
    target_link_libraries(${PROJECT_NAME}
            ${OpenCV_LIBRARIES}
            )
endif ()
