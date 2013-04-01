#include "Trie.h"
#include <iostream>

using namespace std;

Trie::Trie()																		// Constructor for initializing each member of the root node struct
{
	root = new node;
	
	root->character = '\0';
	root->endOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		root->pointers[i] = NULL;
}

void Trie::insertWord(char* word)													// Insert a word into the Trie
{
	node* nodePtr = root;															// Create a nodePtr for traversing, initialize it to root

	while (*word != '\0')															// While there is still a letter left in the word
	{
		int letter = toupper(*word) - 'A';											// Convert the letter of the word to a number, 0=a, 1=b, etc.

		if (nodePtr->pointers[letter] == NULL)										// If there is not already a child node for that letter, create one
		{
			node* newNode = new node;
			newNode->character = *word;												// Initialize the struct members
			newNode->endOfWord = false;
			for (int i = 0; i < ALPHABET_SIZE; i++)
			{
				newNode->pointers[i] = NULL;
			}
			nodePtr->pointers[letter] = newNode;									// Change the child from pointing to NULL to the new struct
			nodePtr = newNode;														// Update nodePtr for the next loop
		}
		else
		{
			nodePtr = nodePtr->pointers[letter];									// If that child already exists, dig deeper
		}
		word++;																		// Increment word to the next letter
	}
	nodePtr->endOfWord = true;														// When there are no more letters left, whatever the current nodePtr is, is the end of word
}

void Trie::deleteWord(char* word)													// Delete a word from the Trie.
{
	node* nodePtr = root;															// Initialize a traverser to root
	node* previousNode;																// Set up a lagging traverser

	while (*word != '\0' || nodePtr->endOfWord)										// While there is a letter left in the word, or the pointe is the end of the word
	{
		int letter = toupper(*word) - 'A';											// 0=a, 1=b, etc.
		int prevLetter = toupper(*(word-1)) - 'A';									// Keep track of what the previous letter was, so we can use to reset previous node's pointer

		if (nodePtr->endOfWord)														// If we are at the end of the word, the delete the node, so only deleting the last letter of the word asked to be deleted.
		{
			deleteTrie(nodePtr);													// Call deleteTrie on the end node
			previousNode->pointers[prevLetter] = NULL;								// Reset the pointer to NULL for the node that was just deleted
			previousNode->endOfWord = true;											// Set previous node to end of word, so that it can be deleted now
			return;																	// Return once deletion and set up of previous node completes
		}
		else																		// If we aren't at the last letter, then dig deeper and increment to next letter of word
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->pointers[letter];
		}

		word++;
	}
}

bool Trie::searchWord(char* word)													// Search for a word in the Trie
{
	node* nodePtr = root;															// Initialize traverser to root

	while (*word != '\0')															// While there are letters left in the word
	{
		int letter = toupper(*word) - 'A';											// 0=a, 1=b, etc.

		if (nodePtr->pointers[letter] == NULL)										// If the child for that letter is NULL, the word doesn't exist
		{
			return false;
		}
		else																		// If the child for that letter does exist, dig deeper and go to next letter of word
		{
			nodePtr = nodePtr->pointers[letter];
		}

		word++;
	}

	return true;																	// If we exited while loop, and never returned false, then the word exists
}

void Trie::deleteTrie(node* nodePtr)												// Used by destructor and to delete a specific word
{
	for (int i = 0; i < ALPHABET_SIZE; i++)											// If the current nodePtr has a child, call this function recursively on that child
	{
		if (nodePtr->pointers[i] != NULL)
		{
			deleteTrie(nodePtr->pointers[i]);
		}
	}

	delete nodePtr;																	// Once the recursive calling returns, we have reached the end of a chain, so delete the nodePtr
}