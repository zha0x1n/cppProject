#ifndef __BINTREE_IMPLEMENT__
#define __BINTREE_IMPLEMENT__

#include <cstdlib>
#include <memory>
#include <algorithm>
using namespace std;

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x)
{ return x->height = 1 + max( stature(x->lc), stature(x->rc)); }

template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{ while(x) { updateHeight(x); x = x->parent; } }

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{ _size = 1; return _root = new BinNode<T>(e); }

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc; }

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc; }

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) {
	if(x->lc = S->_root) x->lc->parent = x;
	_size += S->_size; updateHeightAbove(x);
	S->_root = NULL; S->_size = 0; release(S); S = NULL;
	return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) {
	if(x->rc = S->_root) x->rc->parent = x;
	_size += S->_size; updateHeightAbove(x);
	S->_root = NULL; S->_size = 0; release(S); S = NULL;
	return x;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x) {
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	int n = removeAt(x); _size -= n; return n;
}

template <typename T>
static int removeAt(BinNodePosi(T) x) {
	if(!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	delete []x; return n;
}

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x) {
	FromParentTo(x) = NULL;
	updateHeightAbove(x->parent);
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL;
	S->_size = x->size(); _size -= S->_size;
	return S;
}

#endif
