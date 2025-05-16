cmake_minimum_required(VERSION 3.30)
project(virtualEcosystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(virtualEcosystem main.cpp
        generatorlosowy.cpp
        generatorlosowy.h
        mieszkaniec.cpp
        mieszkaniec.h
        nisza.cpp
        nisza.h
        organizm.cpp
        organizm.h
        osobniki.cpp
        osobniki.h
        sasiedztwo.cpp
        sasiedztwo.h
        srodowisko.cpp
        srodowisko.h
        ustawienia.h)
