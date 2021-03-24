#include "wordCheck.h"
#include <iostream>
#include <string>
using namespace std;

string wordCheck::CorrectGuess(string userGuess, string wordToGuess) {
	unsigned short int i;
	unsigned short int c;
    string userFoundCharacters= "     ";
    int position;
	//convert letter guess to lower
	for (i = 0; i < userGuess.size(); ++i) {
		c = userGuess[i];
		c = tolower(c);
		userGuess[i] = c;
	}
	//branch for guess of entire word
	if (userGuess.size() > 1) {
		if (userGuess == wordToGuess) {	
			userFoundCharacters = wordToGuess;
		}
	}
    else{
		size_t found = wordToGuess.find(userGuess);
		//places first occurence of userGuess if found
		if (found != string::npos) {
			position = wordToGuess.find(userGuess);
			userFoundCharacters[position] = userGuess[0];
			//checks for repeats, places them in correct order
			for (i = 1; i < wordToGuess.size(); ++i) {
				string repeatCheck = wordToGuess.substr(i, wordToGuess.size());
				found = repeatCheck.find(userGuess);
				if (found != string::npos) {
					position = repeatCheck.find(userGuess);
					userFoundCharacters[position + i] = userGuess[0];
				}
			}
		}
      return userFoundCharacters;
	}

}
string wordCheck::WrongGuess(string userGuess, string wordToGuess) {
	string userWrongCharacters = "";

	if (userGuess.size() == 1) {
		//searches string for userGuess
		size_t found = wordToGuess.find(userGuess);
		//places first occurence of userGuess if found
		if (found == string::npos) {

			userWrongCharacters.append(userGuess);
		}
	}
	return userWrongCharacters;

}
