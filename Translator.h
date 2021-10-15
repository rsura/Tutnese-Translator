/**
 * Header File: Translator.h
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
using namespace std;

class Translator{
    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string word);
        string translateEnglishSentence(string sentence);
    private:
        string trimString(string phrase); // private because trimming the string is irrelevant for a "public" method of this class

};

#endif
