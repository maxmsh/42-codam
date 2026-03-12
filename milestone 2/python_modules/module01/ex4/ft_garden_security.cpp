#include <iostream>
#include <string>

class Plant
{
public:
	std::string name;
	int height, age;

	Plant(std::string n, int h, int a) : name(n), height(h), age(a)
	{
	}
};

class SecurePlant : public Plant
{
public:
SecurePlant(std::string n, int h, int a) : Plant(n, h, a) {}

int get_height()
{
	return (height);
}

int get_age()
{
	return (age);
}

void set_height(int new_height)
{
	if (new_height <= 0)
	{
		std::cout << "Invalid operation attempted: height " << new_height << "cm [REJECTED]" << std::endl;
		std::cout << "Security: Negative height rejected" << std::endl;
	}
	else if (new_height >= 0)
	{
		height = new_height;
		std::cout << "Height updated: "  << new_height << "cm [OK]" << std::endl;
	}
}

void set_age(int new_age)
{
	if (new_age <= 0)
	{
		std::cout << "Invalid operation attempted: age " << new_age << " days [REJECTED]" << std::endl;
		std::cout << "Security: Negative age rejected" << std::endl;
	}
	else if (new_age >= 0)
	{
		age = new_age;
		std::cout << "Age updated: "  << new_age << " days [OK]" << std::endl;
	}
}

void print_info()
{	
	std::cout << "Current plant: " << name << " (" << height << "cm, " << age << " days) " << std::endl;
}

};

int main()
{
	SecurePlant rose("Rose", 1, 1);
	std::cout << "=== Garden Security System ===" << "\n";
	std::cout << "Plant created: " << rose.name << "\n";
	rose.set_height(25);
	rose.set_age(30);
	std::cout << "\n";
	rose.set_height(-5);
	std::cout << "\n";
	rose.print_info();
}