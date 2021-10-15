/**
 * Implementation File: TutToEngTranslator.cpp
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#include "TutToEngTranslator.h"

using namespace std;

/**
 * Default constructor
 */
TutToEngTranslator::TutToEngTranslator(){
    // empty body - no code necessary
}

/**
 * Destructor
 */
TutToEngTranslator::~TutToEngTranslator(){
    // empty body - no code necessary
}

/**
 * Makes the entire string lowercase (used for case-insensitive substring checking in this class specifically)
 *
 * @param A string of characters representing a word, sentence, or phrase
 * @return A string of characters all in lowercase
 */
string TutToEngTranslator::lowercaseString(string s){
    for (int i = 0; i < s.length(); ++i) { // iterates through a string and makes all letters lowercase
        s[i] = tolower(s[i]);
    }
    return s;
}

/**
 * Translates the first tutnese character (or non-translatable tutnese character) of the sentence
 * and updates the sentence by removing the tutnese "character" and returns the translated English character
 *
 * @param A string of characters representing a word, sentence, or phrase
 * @return A string of the english translation of the first tutnese character
 */
string TutToEngTranslator::translateAndUpdate(string& sentence){
    string translation = "";
    if (sentence == "") { // in case an empty string is passed
        return "";
    }

    if (toupper(sentence[0]) == tolower(sentence[0])) { // character is non alphabetical
        translation += sentence[0];
        sentence = sentence.substr(1,sentence.length());
        return translation;
    }

    bool isUpper = (sentence[0] == toupper(sentence[0])); // if the tutnese "character" is upper case
    string tempString = lowercaseString(sentence); // to prevent calling lowercaseString to keep checking for a character of the Tutnese sentence

    // if it's a vowel (checks if e isn't followed by x as well, since "ex" translates to x)
    if (tempString[0] == 'a' || (tempString[0] == 'e' && tempString[1] != 'x') || tempString[0] == 'i' || tempString[0] == 'o' || tempString[0] == 'u') {
        translation += tempString[0];
        sentence = sentence.substr(1,sentence.length());
    } else if (tempString.substr(0,4) == "squa"){ // double letter cases
        if (tempString[4] == 't') { // double vowel or double 't'
            if (tempString.substr(0,7) == "squatut") { // double t
                translation = "tt";
                sentence = sentence.substr(7,sentence.length());
            }
            else { // double vowel
                translation += tempString[5];
                translation += tempString[5];
                sentence = sentence.substr(6,sentence.length());
            }
        }
        else { // double consonant
            sentence = sentence.substr(4,sentence.length());
            translation = translateAndUpdate(sentence); // removed squa and recursive call to find double of the next Tutnese "character"
            translation = translation + translation;
        }
    // all the rest of these else-ifs are just checking for the normal cases
    } else if (tempString.substr(0,3) == "bub"){
        translation = "b";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,4) == "cash"){
        translation = "c";
        sentence = sentence.substr(4,sentence.length());
    } else if (tempString.substr(0,3) == "dud"){
        translation = "d";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "fuf"){
        translation = "f";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "gug"){
        translation = "g";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,4) == "hash"){
        translation = "h";
        sentence = sentence.substr(4,sentence.length());
    } else if (tempString.substr(0,3) == "jay"){
        translation = "j";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,4) == "kuck"){
        translation = "k";
        sentence = sentence.substr(4,sentence.length());
    } else if (tempString.substr(0,3) == "lul"){
        translation = "l";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "mum"){
        translation = "m";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "nun"){
        translation = "n";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "pub"){
        translation = "p";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,5) == "quack"){
        translation = "q";
        sentence = sentence.substr(5,sentence.length());
    } else if (tempString.substr(0,3) == "rug"){
        translation = "r";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "sus"){
        translation = "s";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "tut"){
        translation = "t";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "vuv"){
        translation = "v";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,4) == "wack"){
        translation = "w";
        sentence = sentence.substr(4,sentence.length());
    } else if (tempString.substr(0,2) == "ex"){
        translation = "x";
        sentence = sentence.substr(2,sentence.length());
    } else if (tempString.substr(0,3) == "yub"){
        translation = "y";
        sentence = sentence.substr(3,sentence.length());
    } else if (tempString.substr(0,3) == "zub"){
        translation = "z";
        sentence = sentence.substr(3,sentence.length());
    } else { // if somehow the tutnese file has an issue with spelling, it just returns the first character and updates the sentence
        translation += sentence[0];
        sentence = sentence.substr(1,sentence.length());
    }

    if (isUpper) { // if it was upper case, it makes the translation upper case as well
        translation[0] = toupper(translation[0]);
    }
    return translation;
}

/**
 * Translates a string representing a Tutnese sentence to English.
 *
 * @param A string of characters representing a Tutnese word, sentence, or phrase
 * @return A string of characters representing the English translation of the Tutnese sentence
 */
string TutToEngTranslator::returnTranslatedSentence(string tutSentence){
    string translatedSentence = "";

    // This while loop keeps removing Tutnese "characters" from the sentence, translates them, and appends the translation
    // to the newly formed english sentence
    while (tutSentence.length() > 0){
        translatedSentence += translateAndUpdate(tutSentence);
    }
    return translatedSentence;
}
