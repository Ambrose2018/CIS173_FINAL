// ==================================================================================
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
#include "CipherBase.h"
#include "CaesarCipher.h"
#include "Rot13Cipher.h"
#include "Rot47Cipher.h"

using namespace std;

// ==================================================================================

// The following "clearScreen()" function is designed to clear the screen using the very
// old technique of "ANSI Escape Sequences". This will not work on all systems but
// it usually works on Windows and it definitely works on the REPL.IT website.
//
// Function clearScreen() added to MyUtils on 05/09/2019.
// Function updated by Erica Cruz on 05/23/2019 with the following:
//
// From https://repl.it/talk/ask/I-want-to-use-clear-screen-function-in-my-c-code-on-repl/11001
// \033[2J clears the screen and resets the cursor
// and the \033[0;0H moves the cursor to 0,0
//
void clearScreen() {
    cout << "\033[2J\033[0;0H";
}

// ==================================================================================

// The following "trim()" function code is from Stack Overflow. I decided to not
// reinvent the wheel since this is not a required part of the project description.
// All this does is remove leading and trailing spaces from the argument str.
// URL = https://stackoverflow.com/questions/25829143/trim-whitespace-from-a-string
//
// Function trim() added to MyUtils on 05/09/2019.
//
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// ==================================================================================

// Note that the logic for using getline and stringstream came from the following
// forum post:  http://www.cplusplus.com/forum/articles/6046/
// I simply adapted it into some simple functions for repeated use.

// Function inputInteger() added to MyUtils on 05/09/2019.
//
int inputInteger(const string &promptString) {

    string theInput = "";
    int theNumber = 0;

    while (true) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);

        // This code converts from string to number safely.
        stringstream myStream(theInput);
        if (myStream >> theNumber)
            break;
        cout << "Invalid number, please try again" << endl;
    }

    return theNumber;
}

// ----------------------------------------------------------------------------------

// Function inputIntegerChoice() added to MyUtils on 05/09/2019.
//
int inputIntegerChoice(const string &promptString, int _first, int _last) {

    string theInput = "";
    int theNumber = 0;
    bool firstPass = true;

    while (true) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);

        // This code converts from string to number safely.
        stringstream myStream(theInput);
        if ((myStream >> theNumber) && (theNumber >= _first) && (theNumber <= _last))
            break;
        if (firstPass) {
            cout << "\033[5B"; // DOWN 5 LINES
            firstPass = false;
        }

        // The following ANSI escape sequences makes the input error message display
        // as strong ([1m) underlined ([4m) white text ([97m) on a bright red background ([101m),
        // then resets all attributes ([0m) to display normal text after the message.
        cout << "\033[1m\033[4m\033[101m\033[97m";
        cout << " Invalid choice, please try again. ";
        cout << "\033[0m" << endl;
    }

    return theNumber;
}

// ----------------------------------------------------------------------------------

// Function inputDouble() added to MyUtils on 05/09/2019.
//
double inputDouble(const string &promptString) {

    string theInput = "";
    double theNumber = 0;

    while (true) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);

        // This code converts from string to number safely.
        stringstream myStream(theInput);
        if (myStream >> theNumber)
            break;
        cout << "Invalid number, please try again" << endl;
    }

    return theNumber;
}

// ----------------------------------------------------------------------------------


// Function inputString() added to MyUtils on 05/09/2019.
//
string inputString(const string &promptString) {

    string theInput = "";

    // will repeatedly ask for input until string is not empty
    while (theInput.empty()) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);
        theInput = trim(theInput);
    }

    return theInput;
}

// ----------------------------------------------------------------------------------

// Function inputChar() added to MyUtils on 05/09/2019.
//
char inputChar(const string &promptString) {

    string theInput = "";

    // will repeatedly ask for input until string is not empty
    // then will return the first non-blank character entered.
    while (theInput.empty()) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);
        theInput = trim(theInput);
    }

    return theInput.at(0);
}

// ----------------------------------------------------------------------------------

// Function inputYNchoice() added to MyUtils on 05/19/2019.
//
bool inputYNchoice(const string &promptString) {

    const string NoYes = "NnYy";
    string theInput = "";
    char firstChar = '\n';
    bool validChar = false;

    // will repeatedly ask for input until string starts with
    // one of the following 4 characters: "NnYy"
    // then will return either true (for "yes" answers) or
    // false (for "no" answers).

    while (theInput.empty() || !validChar) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);
        theInput = trim(theInput) + "_";
        firstChar = theInput.at(0);
        validChar = NoYes.find(firstChar) != string::npos;
        //   NOT ---^ 			 ^--- find() returns location index of first char if found or else string::npos if not found.
    }

    return static_cast<bool>(NoYes.find(firstChar) / 2);
    //                       ^--- expression resolves as either 0 (boolean false) or 1 (boolean true).
}

// ----------------------------------------------------------------------------------

// Function pressEnterToContinue() added to MyUtils on 05/27/2019.
//
void pressEnterToContinue(const string &promptString) {

    string theInput = "";
    char firstChar = '\n';
    bool validChar = false;

    while (theInput.empty() || !validChar) {
        cout << promptString;
        // cin.ignore(1000,'\n');
        getline(cin, theInput);
        theInput = trim(theInput) + "\n";
        firstChar = theInput.at(0);
        validChar = firstChar == '\n';
    }
    return;
}

// ==================================================================================

// START METHOD ansiBoxText() added to MyUtils on 05/29/2019.
//
void ansiBoxText(const string &promptString, const string &boxedText, int boxType) {

// =============================================================== START OF BOXDRAW CHARACTER DEFINITIONS ==============================
		
	// light density block
	const string lineBlock1  = "░"  ; // * Extended ASCII character * 

	// medium density block
	const string lineBlock2  = "▒"  ; // * Extended ASCII character * 

	// high density block
	const string lineBlock3  = "▓"  ; // * Extended ASCII character * 

	// single line boxdraw characters
	const string line11NW  = "┌"  ; // * Extended ASCII character * 
	const string line11NE  = "┐"  ; // * Extended ASCII character * 
	const string line11SW  = "└"  ; // * Extended ASCII character * 
	const string line11SE  = "┘"  ; // * Extended ASCII character * 
	const string line11NL  = "─"  ; // * Extended ASCII character * 
	const string line11SL  = "─"  ; // * Extended ASCII character * 
	const string line11EL  = "│"  ; // * Extended ASCII character * 
	const string line11WL  = "│"  ; // * Extended ASCII character * 
	const string line11NT  = "┬"  ; // * Extended ASCII character * 
	const string line11ST  = "┴"  ; // * Extended ASCII character * 
	const string line11ET  = "┤"  ; // * Extended ASCII character * 
	const string line11WT  = "├"  ; // * Extended ASCII character * 
	const string line11XP  = "┼"  ; // * Extended ASCII character * 
	
	// double line boxdraw characters
	const string line22NW  = "╔"  ; // * Extended ASCII character * 
	const string line22NE  = "╗"  ; // * Extended ASCII character * 
	const string line22SW  = "╚"  ; // * Extended ASCII character * 
	const string line22SE  = "╝"  ; // * Extended ASCII character * 
	const string line22NL  = "═"  ; // * Extended ASCII character * 
	const string line22SL  = "═"  ; // * Extended ASCII character * 
	const string line22EL  = "║"  ; // * Extended ASCII character * 
	const string line22WL  = "║"  ; // * Extended ASCII character * 
	const string line22NT  = "╦"  ; // * Extended ASCII character * 
	const string line22ST  = "╩"  ; // * Extended ASCII character * 
	const string line22ET  = "╣"  ; // * Extended ASCII character * 
	const string line22WT  = "╠"  ; // * Extended ASCII character * 
	const string line22XP  = "╬"  ; // * Extended ASCII character * 

// ================================================================= END OF BOXDRAW CHARACTER DEFINITIONS ==============================

	// CODE STARTS HERE FOR METHOD void ansiBoxText(const string &promptString, const string &boxedText, int boxType) {

	string prefixString = promptString;
	int prefixSize = promptString.length();
	int keystrSize = boxedText.length();

	if (boxType == 1) {

		for (int i = 0; i < prefixSize; ++i) {
			prefixString.at(i) = ' ';
		}	

		// top row output
		cout << promptString << " " << line11NW << line11NL;
		for (int i = 0; i < keystrSize; ++i) {
			cout << line11NL;
		}	
		cout << line11NL << line11NE << endl;

		// middle row output
		cout << prefixString << " " << line11WL << " ";
		cout << boxedText;
		cout << " " << line11EL << endl;

		// bottom row output
		cout << prefixString << " " << line11SW << line11SL;
		for (int i = 0; i < keystrSize; ++i) {
			cout << line11SL;
		}	
		cout << line11SL << line11SE << endl; 
		
	}

	if (boxType == 2) {

		for (int i = 0; i < prefixSize; ++i) {
			prefixString.at(i) = ' ';
		}	

		// top row output
		cout << promptString << " " << line22NW << line22NL;
		for (int i = 0; i < keystrSize; ++i) {
			cout << line22NL;
		}	
		cout << line22NL << line22NE << endl;

		// middle row output
		cout << prefixString << " " << line22WL << " ";
		cout << boxedText;
		cout << " " << line22EL << endl;

		// bottom row output
		cout << prefixString << " " << line22SW << line22SL;
		for (int i = 0; i < keystrSize; ++i) {
			cout << line22SL;
		}	
		cout << line22SL << line22SE << endl; 
		
	}

}  	// END METHOD void ansiBoxText(const string &promptString, const string &boxedText, int boxType) {

// ==================================================================================

// ############### NOTHING BELOW THIS LINE UNLESS REPLIT SCREWS UP ##############################################################################################
