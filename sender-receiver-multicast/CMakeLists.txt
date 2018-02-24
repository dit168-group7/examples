# CMAKE REQUIREMENT
cmake_minimum_required(VERSION 3.5)

# PROJECT NAME
project(examples)

# STANDARDS
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# VARS
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# PACKAGES
find_package(libcluon REQUIRED)

# INCLUDES
include_directories(SYSTEM ${CLUON_INCLUDE_DIRS})
include_directories(${LIB_DIR})
include_directories(${TEST_DIR})

# BUILDING messages.odvd
add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/messages.cpp
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                   COMMAND cluon-msc --cpp-sources --cpp-add-include-file=messages.hpp --out=${CMAKE_BINARY_DIR}/messages.cpp ${SOURCE_DIR}/messages.odvd
                   COMMAND cluon-msc --cpp-headers --out=${CMAKE_BINARY_DIR}/messages.hpp ${SOURCE_DIR}/messages.odvd
                   DEPENDS ${SOURCE_DIR}/messages.odvd)
include_directories(SYSTEM ${CMAKE_BINARY_DIR})

# BUILD C++ FILES
add_executable(${PROJECT_NAME}-multicast-sender ${SOURCE_DIR}/sender.cpp ${CMAKE_BINARY_DIR}/messages.cpp)
target_link_libraries(${PROJECT_NAME}-multicast-sender ${CLUON_LIBRARIES})

add_executable(${PROJECT_NAME}-multicast-receiver ${SOURCE_DIR}/receiver.cpp ${CMAKE_BINARY_DIR}/messages.cpp)
target_link_libraries(${PROJECT_NAME}-multicast-receiver ${CLUON_LIBRARIES})

# TESTING

