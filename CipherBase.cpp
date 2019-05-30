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

int CipherBase::FindIndex(char currChar) {

    int index = -1;  // preset index to default for not found.

    for (unsigned int i = 0; i < cipherAlphabet.size(); ++i) {
        if (currChar == cipherAlphabet.at(i)) {
            index = i;
        }
    }

    return index;

};

// Default constructor
CipherBase::CipherBase() {
    cipherAlphabet = "abcdefghijklmnopqrstuvwxyz";
};

//limit shift input range OR use modulo
string CipherBase::Encrypt(string inputMsg, int shift) {

    string tmpString = "";
    outEncrypt = "";
    inEncrypt = inputMsg;
    int newPos = 0;
    /* - NOTE: variable newPos is assigned by expressions that resolve to type (unsigned long long int).
       - Do **NOT** change or force cast these types because it will cause an out_of_range exception. 		*/
    int currPos = 0;
    char tmpChar = 'x';
    bool wasUpper = false;

    //Iterate through string parameter inputMsg
    for (unsigned int i = 0; i < inputMsg.size(); ++i) {

        //Keep track of uppercase characters before casting to lowercase
        if (isupper(inEncrypt.at(i))) {
            wasUpper = true;
            //Change uppercase to lowercase character (to find in alphabet), remember upper
            inEncrypt.at(i) = static_cast<char>(tolower(inEncrypt.at(i)));
        } else {
            wasUpper = false;
        }

        //Set current position of character in alphabet
        currPos = FindIndex(inEncrypt.at(i));

        //Handle LEFT shift
        if (shift < 0) {
            //Make shift positive to play nice with % (for shift abs val > index range)
            shift *= -1;
            //Set encrypted character position in alphabet based on shift from current position
            newPos = (currPos - (shift % cipherAlphabet.size()));
            //Change shift back to negative value
            shift *= -1;
        } else {//Handle RIGHT shift
            //Set encrypted character position in alphabet based on shift from current position
            newPos = currPos + (shift % cipherAlphabet.size());
        }

        //Handle character that is not in the alphabet
        if (currPos == -1) {
            //character unchanged, assigned to string holder
            tmpString = inEncrypt.at(i);
        } else {//Handle characters found in alphabet
            //Handle encrypted character positions that are negative
            if (newPos < 0) {
                //Reorient encrypted character position to corresponding positive position
                newPos = (cipherAlphabet.size()) + newPos;
            } else if (newPos > (cipherAlphabet.size() -
                                 1)) {//Handle encrypted character positions that are higher than the last index of the alphabet
                //Reorient encrypted character position to corresponding position within index range of alphabet
                newPos = newPos - (cipherAlphabet.size());
            }
            //Assign new encrypted character to string holder
            tmpString = cipherAlphabet.at(newPos);
        }

        //Handle characters that used to be uppercase
        if (wasUpper) {
            //Change character back to uppercase
            tmpChar = static_cast<char>(toupper(cipherAlphabet.at(newPos)));
            //Assign now uppercase character to string holder
            tmpString = tmpChar;
        }

        //Append the string holder to the encrypted string to be returned
        outEncrypt.append(tmpString);
    }
    //After iterating through whole string, return encrypted version
    return outEncrypt;
};

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
