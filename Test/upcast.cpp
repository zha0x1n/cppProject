#include <iostream>

class A {
private:
	int i;
public:
	A() : i(10) {}
	void self() { std::cout << "A: " << i << std::endl; }
	virtual void f() { std::cout << "A: " << i << std::endl; }
};

class B : public A {
private:
	int j;
public:
	B() : j(20) {}
	int self() { std::cout << "B: " << j << std::endl; return 0; }
	virtual void f() { std::cout << "B: " << j << std::endl; }
};

int main() { 
	A a;
	B b;
	a.self();
	b.self();
	A* p = &b;
	p->self();
	p->f();
	return 0;
}
