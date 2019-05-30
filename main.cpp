// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

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

int main() {

    // Initialize
    clearScreen();

    // Execute
    CipherMenus::showMainMenu();

    // Terminate
    cout << "\n DONE \n\n\n";

    return 0;
}

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
