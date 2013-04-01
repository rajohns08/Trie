#ifndef TRIE_H
#define TRIE_H

#include <cstdlib>

class Trie																				// Class for a Trie data structure for characters
{
private:
	static const int ALPHABET_SIZE = 26;												// Only accepting characters, so each node has 26 children

	struct node																			// Structure for each node. Each node contains a character, endOfWord boolean, and 26 pointers to children
	{
		char character;
		bool endOfWord;
		node* pointers[ALPHABET_SIZE];
	};

	node* root;																			// Root node of Trie

	void deleteTrie(node* nodePtr);														// Completely remove Trie from memory, called by destructor

public:
	Trie();																				// Constructor sets all children pointers to NULL
	void insertWord(char* word);
	void deleteWord(char* word);														// Delete a specific word from the Trie. Only partially implemented
	bool searchWord(char* word);														// Check to see if a word exists in the Trie
	~Trie()
		{ deleteTrie(root); }
};

#endif
