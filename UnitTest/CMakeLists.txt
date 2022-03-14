project(Google_tests)

add_subdirectory(c:\\googletest c:\\googletest\\build)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "c:\\SFML-2.5.1-clion\\SFML-2.5.1\\lib\\cmake\\SFML")


set(CMAKE_MODULE_PATH "${cmaKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2.5 REQUIRED graphics network audio window system)

add_executable(Google_Tests_run BitsTest/BitsTest.cpp
        ../engine/bits/Bits.h ../engine/bits/Bits.cpp
        ../engine/Map.h ../engine/Map.cpp
        ../engine/bloks/Type.cpp ../engine/bloks/Type.h
        ../engine/bloks/Object.cpp ../engine/bloks/Object.h
        ../engine/bloks/PowerData.h
        ../engine/GeneralTexture.cpp ../engine/GeneralTexture.h
        ../Blocks.cpp
        MapSaveTest/MapTest.cpp EnergyTest/EnergyTest.cpp)
target_link_libraries(Google_Tests_run sfml-graphics sfml-system  gtest gtest_main)