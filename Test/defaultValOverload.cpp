#include <iostream>

void print(int a);
void print(int a, int b);

void print(int a) {
	std::cout << "first " << a << std::endl;
}

void print(int a, int b) {
	std::cout << "second " << a << ' ' << b << std::endl;
}

int main() {
	print(1);
	print(1,2);
}
