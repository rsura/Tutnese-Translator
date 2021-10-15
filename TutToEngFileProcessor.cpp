/**
 * Implementation File: TutToEngFileProcessor.cpp
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#include <fstream>
#include "TutToEngFileProcessor.h"
#include "TutToEngTranslator.h"

using namespace std;

/**
 * Default constructor
 */
TutToEngFileProcessor::TutToEngFileProcessor(){
    // empty body - no code necessary
}

/**
 * Destructor
 */
TutToEngFileProcessor::~TutToEngFileProcessor(){
    // empty body - no code necessary
}

/**
 * Takes the name of an input file name and an output file name to translate the
 * Tutnese text from the input text file and put the English translation in an output file.
 *
 * @param the name of the input file (including the extension)
 * @param the name of the output file (including the extension)
 */
void TutToEngFileProcessor::processFile(string inputFile, string outputFile){
    ifstream fileReader;
    fileReader.open(inputFile); // opens input file with the name (inputFile)

    if(!fileReader.is_open()){ // checks if the file isn't open and gives a message to the user to fix it
        cout << "\nOops! No file found with the name of \"" << inputFile << "\"." << endl;
        cout << "Unfortunately, \"" << outputFile << "\" will not be created, as the input file was unaccessable." << endl;
        cout << "Please check if the file is in the wrong file directory, has the proper reading permissions or if you have provided the extension for the file name." << endl;
    } else {
        TutToEngTranslator *t = new TutToEngTranslator(); // new Tutnese to English translator

        ofstream fileWriter;
        fileWriter.open(outputFile); // creates output file with the name (outputFile)

        string fileLine; // represents each line of text of the inputFile

        while (getline(fileReader,fileLine)) { // gets each line of the file

            if (fileLine.length() == 0) { // empty line
                fileWriter << endl; // add that empty line if the input file's line is empty
            } else {
                fileWriter << t->returnTranslatedSentence(fileLine) << endl; // translates the line otherwise
            }
        }

        if (!fileReader.eof()) { // if for some reason the file reader doesn't reach the endl of the file
            cout << "There was an input failure before reaching the end of file." << endl;
        } else { // success message
            cout << "Sucessfully created the Tutnese to English translated file!" << endl;
            cout << "Please check the directory for your file: \"" << outputFile << "\"" << endl;
        }
        fileWriter.close();

        delete t;
    }

    fileReader.close();
}
