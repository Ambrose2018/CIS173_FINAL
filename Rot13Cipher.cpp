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

// Default constructor
Rot13Cipher::Rot13Cipher(int _ver) {

    key1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    key2A = "NOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLM"; // version A - message forced to all caps
    key2B = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"; // version B - message uses existing case
    key2C = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"; // version C - message inverts letter cases

    // Assign one of the three versions above to the key2 string.
		if (_ver == 1) key2 = key2A;
		if (_ver == 2) key2 = key2B;
		if (_ver == 3) key2 = key2C;

    cout << endl;
    // cout << "Key #1: " << key1 << endl;
		ansiBoxText("Key #1:", key1, 2);
    // cout << "Key #2: " << key2 << endl;
		ansiBoxText("Key #2:", key2, 2);
    cout << endl;

};

int Rot13Cipher::FindIndex(char currChar) {

    string haystack = key1;
    string needle = "X";
    needle.at(0) = currChar;

    int index = -1;  // preset index to default for not found.

    // Find first occurrence of substring needle in string haystack.
    size_t found = haystack.find(needle);

    if (found != string::npos) {
//        cout << "First occurrence is " << found << endl;
        index = found;
    } else {
//        cout << "First occurrence NOT FOUND. " << endl;
        index = -1;
    }

    return index;
};

string Rot13Cipher::Encrypt(string inputMsg, int shift) {

    outEncrypt = "";
    int currPos = 0;
    string temp1;
    string temp2;

    //Iterate through string parameter inputMsg
    for (unsigned int i = 0; i < inputMsg.size(); ++i) {

        currPos = FindIndex(inputMsg.at(i));

        if (currPos >= 0) {
            temp2 = key2.at(currPos);
            outEncrypt.append(temp2);   // translate current char from key1 to key2.
        } else {
            temp1 = inputMsg.at(i);
            outEncrypt.append(temp1);   // unidentified character remains as-is in output,
        }

    }

    //After iterating through whole string, return encrypted version
    return outEncrypt;
};

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
