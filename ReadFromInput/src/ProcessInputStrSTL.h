/*
 * ProcessInputStr.h
 *
 *  Created on: Jul 31, 2015
 *      Author: leon
 */

#ifndef SRC_PROCESSINPUTSTRSTL_H_
#define SRC_PROCESSINPUTSTRSTL_H_



class ProcessInputStrSTL
{
private:
	int nLine;
	int nTotalWords;
	int nUnqWords;
public:
	void processString(std::string strInput);
	std::string readInputString();
};



#endif /* SRC_PROCESSINPUTSTR_H_ */
