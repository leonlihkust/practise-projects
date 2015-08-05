/*
 * main.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: leon
 */

#include <iostream>
#include <cstdlib>
#include "ProcessInputStr.h"
#include "ProcessInputStrSTL.h"
using namespace std;

int main()
{
	ProcessInputStrSTL* processInputStr = new ProcessInputStrSTL();
	string strInput = processInputStr->readInputString();
	processInputStr->processString(strInput);
	delete processInputStr;
	return 1;
}
