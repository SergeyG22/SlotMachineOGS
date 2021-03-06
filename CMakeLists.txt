cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
set(PROJECT_NAME SlotMachineOGS)
project(${PROJECT_NAME})
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDART 17)

# Google tests

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/src/View/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/View/*.c"
        "${PROJECT_SOURCE_DIR}/src/Facades/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Facades/*.c"
        "${PROJECT_SOURCE_DIR}/src/Controller/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Controller/*.c"
        "${PROJECT_SOURCE_DIR}/src/Model/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Model/*.c"
        "${PROJECT_SOURCE_DIR}/src/Graphics/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Graphics/*.c"
        "${PROJECT_SOURCE_DIR}/src/Backend/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Backend/*.c"		
		"${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"
)

file(GLOB tests						   
		"${PROJECT_SOURCE_DIR}/tests/*.cpp"
		"${PROJECT_SOURCE_DIR}/tests/*.c"
		"${PROJECT_SOURCE_DIR}/tests/*.cc"
        "${PROJECT_SOURCE_DIR}/include/View/*.h"
        "${PROJECT_SOURCE_DIR}/include/View/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/View/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/View/*.c"
		"${PROJECT_SOURCE_DIR}/include/Facades/*.h"
        "${PROJECT_SOURCE_DIR}/include/Facades/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Facades/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Facades/*.c"
		"${PROJECT_SOURCE_DIR}/include/Controller/*.h"
        "${PROJECT_SOURCE_DIR}/include/Controller/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Controller/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Controller/*.c"
		"${PROJECT_SOURCE_DIR}/include/Model/*.h"
        "${PROJECT_SOURCE_DIR}/include/Model/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Model/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Model/*.c"
		"${PROJECT_SOURCE_DIR}/include/Graphics/*.h"
        "${PROJECT_SOURCE_DIR}/include/Graphics/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Graphics/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Graphics/*.c"
		"${PROJECT_SOURCE_DIR}/include/Backend/*.h"
        "${PROJECT_SOURCE_DIR}/include/Backend/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Backend/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Backend/*.c"		
        "${PROJECT_SOURCE_DIR}/src/config.cpp"
		"${PROJECT_SOURCE_DIR}/include/config.h"
)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_executable(
	${PROJECT_NAME}
	${sources}
)

add_executable(
	google_tests
	${tests}
)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")

# SFML 2.5.1 

find_package(SFML REQUIRED)

if(SFML_FOUND)
		target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})
		target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio sfml-graphics sfml-system sfml-window sfml-network)
        target_include_directories(google_tests PRIVATE ${SFML_INCLUDE_DIR})
        target_link_libraries(google_tests PRIVATE gtest_main sfml-audio sfml-graphics sfml-system sfml-window sfml-network)
endif()


include(GoogleTest)
gtest_discover_tests(google_tests)