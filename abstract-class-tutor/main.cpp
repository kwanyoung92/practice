#include <iostream>

using namespace std;

class Animal {
	public :
		Animal() {}
		virtual ~Animal() {}
		virtual void speak() = 0;
};

class Dog : public Animal {
	public :
		Dog() : Animal() {}
		void speak() {
			cout << "왈왈" << endl;
		}
};

class Cat : public Animal {
	public :
		Cat() : Animal() {}
		void speak() {
			cout << "야옹" << endl;
		}
};

int main() {
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	Animal *ani = new Animal();

	dog->speak();
	cat->speak();

	return 0;
}

