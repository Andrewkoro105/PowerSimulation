cmake_minimum_required(VERSION 3.21)
project(_PowerSimulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(_PowerSimulation engine/main.cpp engine/Camera.cpp engine/Camera.h engine/Map.cpp engine/Map.h engine/bloks/Object.cpp engine/bloks/Object.h engine/Game.cpp engine/Game.h engine/World.cpp engine/World.h engine/bloks/Type.cpp engine/bloks/Type.h engine/bits/Bits.h engine/bits/Bits.cpp control/Control.cpp control/Control.h control/Keyboard.cpp control/Keyboard.h control/Mouse.cpp control/Mouse.h Blocks.cpp engine/Inventory.cpp engine/Inventory.h engine/GeneralTexture.cpp engine/GeneralTexture.h UnitTest/BitsTest/BitsTest.cpp engine/bloks/PowerData.h)

set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "c:\\SFML-2.5.1-clion\\SFML-2.5.1\\lib\\cmake\\SFML")


set(CMAKE_MODULE_PATH "${cmaKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2.5 REQUIRED graphics network audio window system)

target_link_libraries(_PowerSimulation sfml-graphics sfml-system gtest gtest_main)

add_subdirectory(UnitTest)