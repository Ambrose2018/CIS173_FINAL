// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

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

class CaesarCipher {

private:

    string inEncrypt;
    string outEncrypt;
    string cipherAlphabet;

    int FindIndex(char currChar);

public:

    CaesarCipher(); // default constructor

    string Encrypt(string inputMsg, int shift = 3); // core routine for the project

};

#endif

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
