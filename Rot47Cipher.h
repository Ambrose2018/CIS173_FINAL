// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

#ifndef ROT47CIPHER_H
#define ROT47CIPHER_H

#include <string>
#include <iostream>
#include <sstream>
#include "MyUtils.h"
#include "CipherMenus.h"
#include "CipherBase.h"
#include "CaesarCipher.h"
#include "Rot13Cipher.h"
#include "Rot47Cipher.h"

using namespace std;

class Rot47Cipher {

private:

    string inEncrypt;
    string outEncrypt;
    string cipherAlphabet;
    string key1, key2;

    int FindIndex(char currChar);

public:

    Rot47Cipher(); // default constructor

    string Encrypt(string inputMsg, int shift = 47); // core routine for the project

};

#endif

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
