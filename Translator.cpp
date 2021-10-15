/**
 * Implementation File: Translator.cpp
 *
 * Full Name: Rahul Sura
 * Chapman email: sura@chapman.edu
 * Course: CPSC 350-03
 * Project: Tutnese and English Translator
 */

#include "Translator.h"
#include "Model.h"
#include <iostream>

using namespace std;

/**
 * Default constructor
 */
Translator::Translator(){
    // empty body - no code necessary
}

/**
 * Destructor
 */
Translator::~Translator(){
    // empty body - no code necessary
}

/**
 * Trims the spaces from the beginning and end of a string
 *
 * @param A string of characters
 * @return A string of characters that don't containing leading or trailing spaces
 */
string Translator::trimString(string phrase){
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
 * Translates a string of characters that represents an English word. Trims leading
 * and trailing spaces of that string, and if there are multiple words, only takes
 * the first word and translates that into Tutnese form
 *
 * @param A string of characters that represents a word
 * @return The Tutnese translation of the word
 */
string Translator::translateEnglishWord(string word){
    word = trimString(word);
    word = word.substr(0,word.find(" ")); // to make sure it's a word and not sentence, it translates the first word
    string translation = ""; // variable for the translated Tutnese word
    Model *translator = new Model();

    for (int i = 0; i < word.length() - 1; ++i) { // up to (size - 1) because it's comparing to the next character
        if (tolower(word[i]) != tolower(word[i+1])) { // default, most common case (different consecutive letters)
            translation += translator->translateSingleCharacter(word[i]);
        } else if (toupper(word[i]) == tolower(word[i+1])){ // checks if there are 2 consecutive non alphabetic characters (like "...")
            translation += translator->translateSingleCharacter(word[i]);
        } else { // translates the two consecutive characters
            translation += translator->translateDoubleCharacter(word[i]);
            i++;
        }
    }

    // Following if condition accounts for the last character that is not accounted for in the for loop
    if ((tolower(word[word.length()-1]) != tolower(word[word.length()-2])) || (tolower(word[word.length()-1]) == tolower(word[word.length()-2]) && tolower(word[word.length()-1]) == tolower(word[word.length()-3]))) {
        translation += translator->translateSingleCharacter(word[word.length()-1]);
    }
    // If there are 2 consecutive non alphabetic characters (like "..") at the end of the string, then this next condition accounts for that
    else if(tolower(word[word.length()-1]) == toupper(word[word.length()-2])) {
        translation += translator->translateSingleCharacter(word[word.length()-1]);
    }

    delete translator;
    return translation;
}

/**
 * Translates a string of characters that represents an English sentence. Trims leading
 * and trailing spaces of the sentence and translates that into Tutnese form
 *
 * @param A string of characters that represents a word
 * @return The Tutnese translation of the word
 */
string Translator::translateEnglishSentence(string sentence){
    string newSentence = ""; // variable for the translated Tutnese sentence

    // this while loop checks if the sentence still has words or not, and translates each word and appends it to newSentence
    while (sentence.length() != 0 && (sentence.find(" ") >= 0 && sentence.find(" ") < sentence.length())) {
        newSentence += translateEnglishWord(sentence.substr(0,sentence.find(" "))) + " "; // adding the translated word and a space
        sentence = sentence.substr(sentence.find(" ") + 1, sentence.length()); // removes the front-most word from original sentence variable
        sentence = trimString(sentence); // just in case there are more leading spaces
    }

    newSentence += translateEnglishWord(sentence); // translates the last word, since it's not accounted for already

    return newSentence;

}
