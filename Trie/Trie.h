#ifndef TRIE_H
#define TRIE_H

#include <cstdlib>

class Trie
{
private:
	static const int ALPHABET_SIZE = 26;

	struct node
	{
		char character;
		bool endOfWord;
		node* pointers[ALPHABET_SIZE];
	};

	node* root;

	void deleteTrie(node* nodePtr);

public:
	Trie();
	void insertWord(char* word);
	void deleteWord(char* word);
	bool searchWord(char* word);
	~Trie()
		{ deleteTrie(root); }
};

#endif
