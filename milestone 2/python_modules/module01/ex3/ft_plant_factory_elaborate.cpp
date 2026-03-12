#include <iostream>
#include <limits>
#include <string>
#include <vector>

class Plant
{
  public:
	std::string name;
	int height, age;

	Plant(std::string n, int h, int a) : name(n), height(h), age(a)
	{
	}
};

void	ft_plant_factory(void)
{
	int		amount;
	char	name[100];

	amount = 0;
	std::cout << "How many plants would you like to create? ";
	std::cin >> amount;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::vector<Plant> plants;
	for (int i = 0; i < amount; i++)
	{
		std::string name;
		int height, age;
		std::cout << "\nPlant " << i + 1 << " name: ";
		std::getline(std::cin, name);
		std::cout << "Height: ";
		std::cin >> height;
		std::cout << "Age: ";
		std::cin >> age;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		plants.emplace_back(name, height, age);
	}
	std::cout << "=== Plant Factory Output ===\n";
	for (const auto &plant : plants)
	{
		std::cout << "Created: " << plant.name << " (" << plant.height << "cm"
					<< ", " << plant.age << " days"
					<< ")\n";
	}
	std::cout << "\nTotal plants created: " <<  plants.size() << "\n";
}

int	main(void)
{
	ft_plant_factory();
}
