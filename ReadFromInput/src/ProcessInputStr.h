/*
 * ProcessInputStr.h
 *
 *  Created on: Jul 31, 2015
 *      Author: leon
 */

#ifndef SRC_PROCESSINPUTSTR_H_
#define SRC_PROCESSINPUTSTR_H_

class String
{
private:
	int nSize;
	int nIndex;
	char* content;
public:
	String()
	{
		content = new char[5];
		nSize = 5;
		nIndex = 0;
	}
	void Append(char c)
	{
		if(nIndex + 1 == nSize)
		{
			char* newString = new char[nSize * 2];
			for(int i = 0; i < nIndex; i++)
			{
				newString[i] = content[i];
			}
			char* temp = content;
			content = newString;
			newString = NULL;
			delete[] temp;
			nSize = nSize * 2;
		}
		content[nIndex] = c;
		content[nIndex + 1] = '\0';
		nIndex++;

	}
	bool Compare(String *str)
	{
		if(str->GetIndex() != this->nIndex)
			return false;
		for(int i = 0; i < nIndex; i++)
		{
			if(str->GetContent()[i] != this->content[i])
				return false;
		}
		return true;
	}
	int GetIndex()
	{
		return nIndex;
	}
	bool operator==(const String& str)
	{
		if(str.nIndex != this->nIndex)
			return false;
		for(int i = 0; i < nIndex; i++)
		{
			if(str.content[i] != this->content[i])
				return false;
		}
		return true;
	}
	const char* GetContent(){return content;}
	~String()
	{
		delete[] content;
		content = NULL;
	}
};

/*
 * words list to store words read from standard input
 * using linked list structure to store words
 * */
class WordsList
{
public:
	struct node
	{
		String* strWord;
		node* next;
		node():strWord(NULL),next(NULL){};
	};
private:
	node* head;
	int nWordsCount;
	int nUnqWordsCount;
public:
	WordsList():head(NULL),nWordsCount(0),nUnqWordsCount(0){};
	int GetWordsCount()
	{
		return nWordsCount;
	}
	int GetUnqWordsCount()
	{
		return nUnqWordsCount;
	}
	void addUniqueWord(String* str)
	{
		nWordsCount++;
		node* pNode = head;
		node* pNodePre = head;
		while(pNode != NULL)
		{
			if(str->Compare(pNode->strWord))
				return;
			pNodePre = pNode;
			pNode = pNode->next;
		}
		if(head == NULL)
		{
			head = new node();
			head->strWord = str;
		}
		else
		{
			node* pNewNode = new node();
			pNewNode->strWord = str;
			pNodePre->next = pNewNode;
		}
		nUnqWordsCount++;
	}
	~WordsList()
	{
		node* pNode = head;
		while(head != NULL)
		{
			pNode = head->next;
			delete head->strWord;
			delete head;
			head = pNode;
		}
	}
};

class ProcessInputStr
{
public:
	String* readInputString();
	void processString(String* string);
};



#endif /* SRC_PROCESSINPUTSTR_H_ */
