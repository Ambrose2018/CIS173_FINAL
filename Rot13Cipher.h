// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

#ifndef ROT13CIPHER_H
#define ROT13CIPHER_H

#include <string>
#include <iostream>
#include <sstream>
#include "MyUtils.h"
#include "CipherMenus.h"
#include "CaesarCipher.h"
#include "Rot13Cipher.h"
#include "Rot47Cipher.h"

using namespace std;

class Rot13Cipher {

private:

    string inEncrypt;
    string outEncrypt;
    string cipherAlphabet;
    string key1, key2, key2A, key2B, key2C;

    int FindIndex(char currChar);

public:

    Rot13Cipher(int _ver); // default constructor

    string Encrypt(string inputMsg, int shift = 13); // core routine for the project

};

#endif

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
