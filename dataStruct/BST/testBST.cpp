#include <iostream>
#include "BST.h"

using namespace std;

void printN(char );
int main() {
	BST<char> T;
	int a[10] = {'e', 'b', 'a', 'z', 'g', 'h', 'f', 'i', 'd', 'c'};
	for(int i = 0; i < 10; i++)
		T.insert(a[i]);
	T.travIn(printN);
	cout << "after remove d :" << endl;
	T.remove('d');
	T.travIn(printN);
}

void printN(char x) {
	cout << x << endl;
}
