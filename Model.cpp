/**
 * Implementation File: Model.cpp
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#include "Model.h"
#include <iostream>

using namespace std;

/**
 * Default constructor
 */
Model::Model(){
    // empty body - no code necessary
}

/**
 * Destructor
 */
Model::~Model(){
    // empty body - no code necessary
}

/**
 * Translates any single alphabetical character into Tutnese form. If a non alphabetical
 * character is given, that character will just be returned as a string
 *
 * @param Any single ASCII character
 * @return The Tutnese translation of that character
 */
string Model::translateSingleCharacter(char singleChar){
    bool isUpperCase = false;
    if (singleChar == toupper(singleChar)) { // checks if the character is upper case or not
        isUpperCase = true;
        singleChar = tolower(singleChar); // makes the character lower case for the time being
    }
    string translation = "";
    switch(singleChar) { //translates the character into tutnese in this switch statement
        case 'b' :
            translation = "bub";
            break;
        case 'c' :
            translation = "cash";
            break;
        case 'd' :
            translation = "dud";
            break;
        case 'f' :
            translation = "fuf";
            break;
        case 'g' :
            translation = "gug";
            break;
        case 'h' :
            translation = "hash";
            break;
        case 'j' :
            translation = "jay";
            break;
        case 'k' :
            translation = "kuck";
            break;
        case 'l' :
            translation = "lul";
            break;
        case 'm' :
            translation = "mum";
            break;
        case 'n' :
            translation = "nun";
            break;
        case 'p' :
            translation = "pub";
            break;
        case 'q' :
            translation = "quack";
            break;
        case 'r' :
            translation = "rug";
            break;
        case 's' :
            translation = "sus";
            break;
        case 't' :
            translation = "tut";
            break;
        case 'v' :
            translation = "vuv";
            break;
        case 'w' :
            translation = "wack";
            break;
        case 'x' :
            translation = "ex";
            break;
        case 'y' :
            translation = "yub";
            break;
        case 'z' :
            translation = "zub";
            break;
        default :
            // This just returns that character if it doesn't fit the criteria,
            // including if the character is non-alphabetical
            translation += singleChar;
    }
    if(isUpperCase){
        translation[0] = toupper(translation[0]); // Makes the translation upper case if the character was upper case
        return translation;
    }


}

/**
 * Translates any alphabetical character that appears twice consecutively into Tutnese
 * form. If a non alphabetical character is given, a string representing two of
 * that character will be returned (such as "&&")
 *
 * @param Any single ASCII character
 * @return The Tutnese translation of that character
 */
string Model::translateDoubleCharacter(char doubleChar){
    bool isUpperCase = false;
    if (doubleChar == toupper(doubleChar)) { // checks if the character is upper case or not
        isUpperCase = true;
        doubleChar = tolower(doubleChar); // makes the character lower case for the time being
    }
    string translation;
    if (doubleChar == 'a' || doubleChar == 'e' || doubleChar == 'i' || doubleChar == 'o' || doubleChar == 'u') { // checks if vowel
        translation = "squat";
        translation += doubleChar;
    } else if(doubleChar == toupper(doubleChar)){ // checks if it's NOT an alphabetic character
        translation += doubleChar;
        translation += doubleChar;
    } else { // checks if it's a consonant
        translation = "squa" + translateSingleCharacter(doubleChar);
    }

    if(isUpperCase){ // Makes the translation upper case if the character was upper case
        translation[0] = toupper(translation[0]);
    }

    return translation;
}
