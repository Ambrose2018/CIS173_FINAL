// Created May 2019 by the software gurus of Erica Cruz and Matt Ambrose.

#include <string>
#include <iostream>
#include "MyUtils.h"

using namespace std;

// Default constructor
Rot47Cipher::Rot47Cipher() {

    //   = "123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_123456789_1234";
    key1 = "                                                                                              ";
    key2 = "                                                                                              ";

    for (int i = 0; i < 47; ++i) {

        key1.at(i) = static_cast<char>('!' + i);
        key1.at(i + 47) = static_cast<char>('P' + i);
        key2.at(i) = static_cast<char>('P' + i);
        key2.at(i + 47) = static_cast<char>('!' + i);

    }

    cout << endl;
    // cout << "Key #1: " << key1 << endl;
		ansiBoxText("Key #1:", key1, 2);
    // cout << "Key #2: " << key2 << endl;
		ansiBoxText("Key #2:", key2, 2);
    cout << endl;

}

int Rot47Cipher::FindIndex(char currChar) {

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
}

string Rot47Cipher::Encrypt(string inputMsg) {

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
}

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
