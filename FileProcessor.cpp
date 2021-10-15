/**
 * Implementation File: FileProcessor.cpp
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#include "FileProcessor.h"
#include "Translator.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Default constructor
 */
FileProcessor::FileProcessor(){
    // empty body - no code necessary
}

/**
 * Destructor
 */
FileProcessor::~FileProcessor(){
    // empty body - no code necessary
}


/**
 * Trims the spaces from the beginning and end of a string
 *
 * @param A string of characters
 * @return A string of characters that don't containing leading or trailing spaces
 */
string FileProcessor::trimString(string phrase){
    int phraseLength = phrase.length();
    for (int i = 0; i < phraseLength; ++i) { // trims beginning of the string's spaces
        if(phrase[i] == ' '){
            phrase = phrase.substr(1,phraseLength);
            phraseLength--;
            i--;
        } else {
            break;
        }
    }

    for (int i = phraseLength - 1; i >= 0; --i) { // trims beginning of the string's spaces
        if(phrase[i] == ' '){
            phrase = phrase.substr(0,phraseLength - 1);
            phraseLength--;
        } else {
            break;
        }
    }

    return phrase;

}

/**
 * Takes the name of an input file name and an output file name to translate the
 * English text from the input text file and put the Tutnese translation in an output file.
 *
 * @param the name of the input file (including the extension)
 * @param the name of the output file (including the extension)
 */
void FileProcessor::processFile(string inputFile, string outputFile){


    ifstream fileReader;
    fileReader.open(inputFile); // opens the input file with the name of inputFile

    Translator *t = new Translator();

    if(!fileReader.is_open()){ // checks if the file is open (meaning if the file exists in the same directory and has permissions to be opened)
        cout << "\nOops! No file found with the name of \"" << inputFile << "\"" << endl;
        cout << "Unfortunately, \"" << outputFile << "\" will not be created, as the input file was unaccessable" << endl;
        cout << "Please check if the file is in the wrong file directory, has the proper reading permissions or if you have provided the extension for the file name" << endl;
    } else {
        ofstream fileWriter;
        fileWriter.open(outputFile); // creates an output file with the name of outputFile
        string fileLine; // represents each line of text of the inputFile

        while (getline (fileReader,fileLine)) {
            fileLine = trimString(fileLine);
            if (fileLine.length() == 0) { // empty line
                fileWriter << endl; // add that empty line
                continue;
            }
            fileWriter << t->translateEnglishSentence(fileLine) << endl;
        }
        if (!fileReader.eof()) { // if for some reason the file reader doesn't reach the endl of the file
            cout << "There was an input failure before reaching the end of file." << endl;
        } else {
            cout << "Sucessfully created the translated file!" << endl;
            cout << "Please check the directory for your file: \"" << outputFile << "\"" << endl;
        }
        fileWriter.close();

    }
    fileReader.close();

}

/**
 * Takes the name of an input file name (with no output file name) to translate
 * the English text from the input text file and put the Tutnese translation in an output file.
 * Since no output file is given, it will give the translation in a file called "DEFAULT_TRANSLATION_FILE.txt"
 *
 * @param the name of the input file (including the extension)
 */
void FileProcessor::processFile(string inputFile){
    string outputFile = "DEFAULT_TRANSLATION_FILE.txt"; // creates the name of the default output file name
    cout << "It appears that you provided \"" << inputFile << "\" as the name of your input file, " <<
    "but provided no name for your output file. The translated file will be output in \"" << outputFile << "\"" << endl;
    processFile(inputFile, outputFile);
}
