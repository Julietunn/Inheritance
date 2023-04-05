#include<iostream>
using namespace std;

class Animal
{
	virtual void sound() = 0;
};
class Cat : public Animal
{
public:
	void sound()
	{
		cout << "Meow" << endl;
	}
};
class Dog : public Animal
{
public:
	void sound()
	{
		cout << "Woof" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Cat tom;
	tom.sound();

	Dog hatico;
	hatico.sound();
}