/**
 * Main Implementation File: main.cpp
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#include "FileProcessor.h"
#include "TutToEngFileProcessor.h"

using namespace std;

/**
 * This main method takes in three command line parameters, the first being the name
 * of the input file (including the extension) containing text to be translated,
 * the second being the name of the output file (also including the extension), and
 * the third, which is the direction of translation. "E2T" represents translating from
 * English to Tutnese and "T2E" represents translating from Tutnese to English.
 *
 * @param Command line parameters, separated by a space
 * @return Exit code
 */
int main(int argc, char** argv) {

    cout << "------------------------------" << endl; // Just highlighting program's output in terminal window

    if(argc >= 4){
        // Not sure why, but I couldn't use argv[3] for boolean comparison, so I put it in this temp variable and it works using that
        string translationDirection = argv[3];

        for (int i = 0; i < translationDirection.length(); ++i) { // makes the translation direction case-insensitive
            translationDirection[i] = tolower(translationDirection[i]);
        }
        if (translationDirection == "t2e") { // Tutnese to English translation
            TutToEngFileProcessor *tep = new TutToEngFileProcessor();
            tep->processFile(argv[1],argv[2]);
            delete tep;
        } else if (translationDirection == "e2t") { // English to Tutnese translation
            FileProcessor *fp = new FileProcessor();
            fp->processFile(argv[1], argv[2]);
            delete fp;
        } else { // If the direction of translation is mistyped
            cout << "Oops! Did you put the direction of translation properly?" << endl;
            cout << "If you want English to Tutnese translation, make your third command line argument as \"E2T\"" << endl;
            cout << "If you want Tutnese to English translation instead, make your third command line argument as \"T2E\"" << endl;
        }
    } else { // If there weren't enough parameters typed
        cout << "It appears that you haven't provided the necessary command line parameters when running this program. Please re-run " <<
        "the program with command line parameters about the input file's name, output file's name, and translation direction (in that order)" << endl;
    }

    cout << "------------------------------" << endl; // Just highlighting program's output in terminal window

    return 0;
}
