#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
	Trie trieObj;

	//char* word = "hey";
	trieObj.insertWord("hey");
	trieObj.insertWord("hello");
	cout << trieObj.searchWord("hey") << endl;

	trieObj.deleteWord("hey");
	cout << trieObj.searchWord("hey") << endl;
	cout << trieObj.searchWord("hello") << endl;


	cin.get();
	return 0;
}
