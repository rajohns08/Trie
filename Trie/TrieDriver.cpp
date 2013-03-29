#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
	Trie trieObj;

	trieObj.insertWord("he");
	cout << trieObj.searchWord("hey") << endl;

	cin.get();
	return 0;
}
