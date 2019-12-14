#ifndef __BINNODE__
#define __BINNODE__

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)
typedef enum{RB_RED,RB_BLACK} RBColor;

template <typename T> struct BinNode {
	T data;
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
	int height;
	int npl;
	RBColor color;
	BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
	int size();
	BinNodePosi(T) insertAsLC(T const& );
	BinNodePosi(T) insertAsRC(T const& );
	BinNodePosi(T) succ();
	template <typename VST> void travLevel(VST& );
	template <typename VST> void travPre(VST& );
	template <typename VST> void travIn(VST& );
	template <typename VST> void travPost(VST& );
	bool operator< (BinNode const& bn) { return data < bn.data; }
	bool operator<= (BinNode const& bn) { return data <= bn.data; }
	bool operator> (BinNode const& bn) { return data > bn.data; }
	bool operator>= (BinNode const& bn) { return data >= bn.data; }
	bool operator== (BinNode const& bn) { return data == bn.data; }
};

#define IsRoot(x) ( !( ( x ).parent ) )
#define IsLChild(x) ( !IsRoot(x) && ( &(x) == (x).parent->lc ) )
#define IsRChild(x) ( !IsRoot(x) && ( &(x) == (x).parent->rc ) )
#define HasParent(x) ( !IsRoot(x) )
#define HasLChild(x) ( !(x).lc )
#define HasRChild(x) ( !(x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( !HasChild(x) )

#define sibling(p) (IsLChild(*(p)) ? (p)->parent->lc : (p)->parent->rc)
#define uncle(x) (sibling(x->parent))
#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x).parent->rc))

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e)
{ return lc = new BinNode(e, this); }

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{ return rc = new BinNode(e, this); }

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST& visit) {
	travIn_R(this, visit);
}

template <typename T> template <typename VST>
void BinNode<T>::travPre(VST& visit) {
	travPre_R(this, visit);
}

template <typename T> template <typename VST>
void BinNode<T>::travPost(VST& visit) {
	travPost_R(this, visit);
}

template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit) {
	if(!x) return;
	visit(x->data);
	travPre_R(x->lc, visit);
	travPre_R(x->rc, visit);
}

template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit) {
	if(!x) return;
	travPre_R(x->lc, visit);
	visit(x->data);
	travPre_R(x->rc, visit);
}


template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit) {
	if(!x) return;
	travPre_R(x->lc, visit);
	travPre_R(x->rc, visit);
	visit(x->data);
}

#include <queue>

template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST& visit) {
	std::queue<BinNodePosi(T)> Q;
	Q.push(this);
	while( !Q.empty() ) {
		BinNodePosi(T) x = Q.front();
		Q.pop();
		visit(x->data);
		if( HasLChild(*x) ) Q.push(x->lc);
		if( HasRChild(*x) ) Q.push(x->rc);
	}
}

template <typename T> int BinNode<T>::size() {
	int s = 1;
	if(lc) s += lc->size();
	if(rc) s += rc->size();
	return s;
}

template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if(rc) {
		s = rc;
		while( HasLChild(*s) ) s = s->lc;
	}else {
		while( IsRChild(*s) ) s = s->parent;
		s = s->parent;
	}
	return s;
}



#endif
