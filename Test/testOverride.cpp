#include <iostream>

class A {
private:
	int i;
public:
	A() : i(0) {}
	void print() {
		std::cout << "A::print(): " << i << std::endl;
	}
	void print(int ii) {
		std::cout << "A::print(ii): " << ii << std::endl;
	}
};

class B : public A {
public:
	void print() {
		std::cout << "B::print(): " << std::endl;
	}
};

int main() {
	A a;
	B b;
	a.print();
	a.print(2);
	b.A::print(2);
	return 0;
}
