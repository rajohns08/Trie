#include "Trie.h"
#include <iostream>

using namespace std;

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

void Trie::deleteWord(char* word)
{
	node* nodePtr = root;

	while (*word != '\0')
	{
		int letter = toupper(*word) - 'A';

		if (nodePtr->pointers[letter] == NULL)
		{
			cout << "That word does not exist" << endl;
		}
		else
		{
			nodePtr = nodePtr->pointers[letter];
		}

		word++;
	}

	// finish implementation

}

bool Trie::searchWord(char* word)
{
	node* nodePtr = root;

	while (*word != '\0')
	{
		int letter = toupper(*word) - 'A';

		if (nodePtr->pointers[letter] == NULL)
		{
			return false;
		}
		else
		{
			nodePtr = nodePtr->pointers[letter];
		}

		word++;
	}

	return true;
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