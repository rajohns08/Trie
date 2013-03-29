#include "Trie.h"

Trie::Trie()
{
	root = new node;
	
	root->character = '\0';
	root->endOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		root->pointers[i] = NULL;
}

void Trie::insertWord(char* word)
{
	node* nodePtr = root;

	while (*word != '\0')
	{

	}
}

void Trie::deleteTrie(node* nodePtr)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (nodePtr->pointers[i] != NULL)
		{
			deleteTrie(nodePtr->pointers[i]);
		}
	}

	delete nodePtr;
}