/*
 * main.cpp
 *
 *  Created on: Jul 30, 2015
 *      Author: leon
 *  A simple program to handle strings from standard input without STL
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "ProcessInputStr.h"
using namespace std;



String* ProcessInputStr::readInputString()
{
	char c;
	String* strInput = new String();
	do{
		c = cin.get();
		if(c == EOF)
			break;
		strInput->Append(c);
	}while(true);
	return strInput;
}

void ProcessInputStr::processString(String* string)
{
	int nLine = 1;
	WordsList* wordslist = new WordsList();
	String* strWord = new String();
	for(int i = 0; i <= string->GetIndex(); i++)
	{
		char c = string->GetContent()[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		{
			strWord->Append(c);
		}
		else
		{
			if(c == 10 || c == EOF)
				nLine++;
			wordslist->addUniqueWord(strWord);
			strWord = new String();
		}
	}
	cout << "Input lines:  "<< nLine << endl;
	cout << "Input words:  "<< wordslist->GetWordsCount() << endl;
	cout << "Input unique words:  "<< wordslist->GetUnqWordsCount() << endl;
	delete strWord;
	delete wordslist;
}




