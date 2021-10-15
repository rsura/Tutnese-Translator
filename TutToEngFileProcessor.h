/**
 * Header File: TutToEngFileProcessor.h
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#ifndef TUTTOENGFILEPROCESSOR_H // header guards
#define TUTTOENGFILEPROCESSOR_H

#include <iostream>

using namespace std;

class TutToEngFileProcessor{
    public:
        TutToEngFileProcessor();
        ~TutToEngFileProcessor();
        void processFile(string inputFile, string outputFile);
};

#endif
