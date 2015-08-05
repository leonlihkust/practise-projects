/*
 * ProcessInputStrSTL.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: leon
 *  A simple program to handle strings from standard input with STL
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include "ProcessInputStrSTL.h"
using namespace std;
string ProcessInputStrSTL::readInputString()
{
	string strInput = "";
	char c;
	do
	{
		c = getchar();
		strInput += c;
	}while(c != EOF);
	return strInput;
}

void ProcessInputStrSTL::processString(string strInput)
{
	map<string,int> unqWords;
	int nLine = 1;
	int nWordsCount = 0;
	string strWord;
	for(unsigned int i = 0; i < strInput.length(); i++)
	{
		if(isalnum(strInput[i]))
			strWord += strInput[i];
		else
		{
			if(strInput[i] == 10 || strInput[i] == EOF)
				nLine++;
			if(strWord.length())
			{
				if(unqWords.find(strWord) == unqWords.end())
					unqWords[strWord] = 1;
				strWord = "";
				nWordsCount++;
			}
		}
	}
	cout << "Input lines:  "<< nLine << endl;
	cout << "Input words:  "<< nWordsCount << endl;
	cout << "Input unique words:  "<< unqWords.size() << endl;
}


