#include <iostream>
#include <string>

	class Plant {
		public:
		std::string name;
		int height, age;

		Plant(std::string n, int h, int a) : name(n), height(h), age(a) {}
	};


int	main()
{
	Plant plantObj1("Rose", 25, 30);
	Plant plantObj2("Lily", 5, 2);
	Plant plantObj3("Apple tree", 450, 675);

	std::cout << "=== Garden Plant Registry ===\n";
	std::cout << plantObj1.name << ":" << " " << plantObj1.height << "cm" << "," << " " << plantObj1.age << " days old\n";
	std::cout << plantObj2.name << ":" << " " << plantObj2.height << "cm" << "," << " " << plantObj2.age << " days old\n";
	std::cout << plantObj3.name << ":" << " " << plantObj3.height << "cm" << "," << " " << plantObj3.age << " days old\n";
}