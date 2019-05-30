// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

#ifndef CIPHERMENU_H
#define CIPHERMENU_H

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

class CipherMenus {

private:

public:

    CipherMenus(); // default constructor

    static void showMainMenu();

};

#endif

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
