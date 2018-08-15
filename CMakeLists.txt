cmake_minimum_required(VERSION 3.9)
project(Lab5_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab5_6
        main.cpp
        src/Tests.cpp headers/Tests.h
        src/Domain/Dog.cpp headers/Domain/Dog.h
        src/Repository/Database.cpp headers/Repository/Database.h
        src/Repository/DynamicVector.cpp headers/Repository/DynamicVector.h
        src/Controller/Controller.cpp headers/Controller/Controller.h
        src/UI/AdminUI.cpp headers/UI/AdminUI.h
        src/UI/UserUI.cpp headers/UI/UserUI.h
        src/Util/Comparator.cpp headers/Util/Comparator.h
        headers/Util/InsertionSort.h
        src/Util/AscAgeComparator.cpp  headers/Util/AscAgeComparator.h
        src/Util/AscNameComparator.cpp headers/Util/AscNameComparator.h)



