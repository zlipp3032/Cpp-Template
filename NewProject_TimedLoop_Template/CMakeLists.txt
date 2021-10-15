cmake_minimum_required(VERSION 2.8)
project(thread-example)


#add_subdirectory(osdk-core)

if (${CMAKE_SYSTEM_NAME} MATCHES Linux)
   add_subdirectory(src)
endif()
