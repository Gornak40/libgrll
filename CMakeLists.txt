cmake_minimum_required(VERSION 3.5)

project(libgrll LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address,undefined,leak -g")

add_library(${PROJECT_NAME} INTERFACE ${PROJECT_NAME}.h)

enable_testing()

FILE(GLOB ComponentsSrc tests/components/*.c)

set(TEST_CMD ${PROJECT_NAME}_test)

add_executable(${TEST_CMD} tests/main.c ${ComponentsSrc})

target_include_directories(${TEST_CMD} PRIVATE .)
target_link_libraries(${TEST_CMD} ${PROJECT_NAME})

foreach(file ${ComponentsSrc})

get_filename_component(test ${file} NAME_WE)
add_test(NAME ${test} COMMAND ${TEST_CMD} ${test})

endforeach()
