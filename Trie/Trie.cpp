#include "Trie.h"
#include <iostream>

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
		int letter = toupper(*word) - 'A';

		if (nodePtr->pointers[letter] == NULL)
		{
			node* newNode = new node;
			newNode->character = *word;
			newNode->endOfWord = false;
			for (int i = 0; i < ALPHABET_SIZE; i++)
			{
				newNode->pointers[i] = NULL;
			}
			nodePtr->pointers[letter] = newNode;
			nodePtr = newNode;
		}
		else
		{
			nodePtr = nodePtr->pointers[letter];
		}
		word++;
	}
	nodePtr->endOfWord = true;
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