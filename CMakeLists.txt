cmake_minimum_required(VERSION 3.14)
project(CIS173_Cipher_Group_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CIS173_Cipher_Group_Project_v2
        CaesarCipher.cpp
        CaesarCipher.h
        CipherMenus.cpp
        CipherMenus.h
        main.cpp
        MyUtils.cpp
        MyUtils.h
        CipherBase.h
        Rot13Cipher.h
        Rot47Cipher.h
        CipherBase.cpp
        Rot13Cipher.cpp
        Rot47Cipher.cpp)
