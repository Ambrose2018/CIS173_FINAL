#ifndef MAMBROSE_MYUTILS_H
#define MAMBROSE_MYUTILS_H

//
// MyUtils created by Matt Ambrose on 05/09/2019.
// inputYNchoice() added on 05/19/2019.
// clearScreen() modified on 05/23/2019 with a contribution from Erica Cruz.
//

#include <string>
#include <iostream>
#include <sstream>
#include "MyUtils.h"
#include "CipherMenus.h"
#include "CaesarCipher.h"
#include "Rot13Cipher.h"
#include "Rot47Cipher.h"

using namespace std;

void clearScreen();          // no parameters

string trim(const string &str);

int inputInteger(const string &promptString);

int inputIntegerChoice(const string &promptString, int _first, int _last);

double inputDouble(const string &promptString);

string inputString(const string &promptString);

char inputChar(const string &promptString);

bool inputYNchoice(const string &promptString);

void pressEnterToContinue(const string &promptString);

void ansiBoxText(const string &promptString, const string &boxedText, int boxType);

#endif //MAMBROSE_MYUTILS_H

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
