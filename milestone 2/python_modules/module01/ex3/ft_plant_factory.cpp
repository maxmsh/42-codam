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

Plant plant_one("Rose", 14, 7);
Plant plant_two("Tulip", 4, 28);
Plant plant_three("Marigold", 7, 61);
Plant plant_four("Lily", 45, 146);
Plant plant_five("Apple tree", 345, 12);

void ft_plant_factory()
{
	std::cout << "=== Plant Factory Output ===\n";
	std::cout << "Created: " << plant_one.name << " (" << plant_one.height << "cm" << ", "  << plant_one.age << " days" << ")" << "\n";
	std::cout << "Created: " << plant_two.name << " (" << plant_two.height << "cm" << ", "  << plant_two.age << " days" << ")" << "\n";
	std::cout << "Created: " << plant_three.name << " (" << plant_three.height << "cm" << ", "  << plant_three.age << " days" << ")" << "\n";
	std::cout << "Created: " << plant_four.name << " (" << plant_four.height << "cm" << ", "  << plant_four.age << " days" << ")" << "\n";
	std::cout << "Created: " << plant_five.name << " (" << plant_five.height << "cm" << ", "  << plant_five.age << " days" << ")" << "\n";
	std::cout << "\n";
	std::cout << "Total plants created: 5\n";
}

int main(void)
{
	ft_plant_factory();
}