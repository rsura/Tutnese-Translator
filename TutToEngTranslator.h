/**
 * Header File: TutToEngTranslator.h
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#ifndef TUTTOENGTRANSLATOR_H // header guards
#define TUTTOENGTRANSLATOR_H

#include <iostream>

using namespace std;

class TutToEngTranslator{
    public:
        TutToEngTranslator();
        ~TutToEngTranslator();
        string returnTranslatedSentence(string engSentence);
    private:
        string lowercaseString(string s); //makes the whole sentence lower case just for substring checking
        string translateAndUpdate(string& sentence); // translates substring and updates the sentence


};

#endif
