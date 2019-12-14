#include <iostream>
#include "binTree.h"

using namespace std;

void printN(char );
int main() {
	BinTree<char> T;
	T.insertAsRoot('a');
	T.insertAsLC(T.root(), '0');
	T.insertAsRC(T.root(), 'b');
	/*
	T.insertAsRC(T.root()->rc, 'c');
	cout << "Pre: " << endl;
	T.travPre(printN);
	cout << "In: " << endl;
	T.travIn(printN);
	cout << "Post: " << endl;
	T.travPost(printN);
	*/
	BinNodePosi(char) r = T.root()->succ();
	cout << " " << endl;
	//char x = r->lc->parent->data;
	//cout << x;	
}

void printN(char x) {
	std::cout << x << std::endl;
}
