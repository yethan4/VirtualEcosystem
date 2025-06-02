cmake_minimum_required(VERSION 3.25)
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
        ustawienia.h
        zlab12.cpp
        zlab12.h)
