#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
	Trie trieObj;

	//char* word = "hey";
	trieObj.insertWord("hey");
	trieObj.insertWord("new");
	cout << trieObj.searchWord("hey") << endl;
	//word = '\0';
	trieObj.deleteWord("hey");
	cout << trieObj.searchWord("hey") << endl;
	cout << trieObj.searchWord("he") << endl;
	trieObj.deleteWord("he");
	cout << trieObj.searchWord("he") << endl;

	cin.get();
	return 0;
}
