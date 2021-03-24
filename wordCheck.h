#pragma once
#ifndef WORDCHECK_H_
#define WORDCHECK_H_
#include <iostream>
#include <string>

using namespace std;


class wordCheck
{
public:
	string CorrectGuess(string userGuess, string wordToGuess);
	string WrongGuess(string userGuess, string wordToGuess);
};


#endif