cmake_minimum_required(VERSION 3.21)
project(_PowerSimulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(_PowerSimulation main.cpp Camera.cpp Camera.h Map.cpp Map.h Object.cpp Object.h Game.cpp Game.h World.cpp World.h Type.cpp Type.h)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "c:\\SFML-2.5.1-clion\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(_PowerSimulation sfml-graphics sfml-system)

set(CMAKE_MODULE_PATH "${cmaKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML 2.5 REQUIRED graphics network audio window system)