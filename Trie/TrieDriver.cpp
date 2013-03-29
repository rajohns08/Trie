#include <iostream>
#include "Trie.h"

using namespace std;

void printChar(char word[]);

int main()
{
	Trie trieObj;

	char* charArray[] = {"bear", "bid", "stock", "set"};

	printChar(charArray[0]);

	cin.get();
	return 0;
}

void printChar(char word[])
{
	int i = 0;
	while (word[i] != '\0')
	{
		cout << word[i] << endl;

		i++;
	}
}