#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
	int x = 5;
	int* ptr = &x;
	int* arr[10] = {ptr};

	cout << ptr << endl;
	cout << arr[0] << endl;

	cin.get();
	return 0;
}