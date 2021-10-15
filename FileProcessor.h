/**
 * Header File: FileProcessor.h
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
using namespace std;

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string inputFile, string outputFile);
        void processFile(string inputFile); // new public method in case output file not provided
    private:
        string trimString(string phrase); // private because trimming the string is irrelevant for a "public" method of this class
};

#endif
