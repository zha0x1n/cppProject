#include <iostream>

class A {
private:
	int i;
public:
	A() : i(10) {}
	void f() { std::cout << "i = : " << i << std::endl; }
};

int main() {
	A a;
	int* p = (int*) &a;
	a.f();
	*p = 20;
	a.f();

	return 0;
}
