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

	Plant plantObj1("Rose", 25, 30);
	Plant plantObj2("Lily", 5, 2);
	Plant plantObj3("Apple tree", 450, 675);

void	ft_plant_growth()
{
	int	i;
	int startheight1 = plantObj1.height;

	i = 1;
	while (i <= 7)
	{
		std::cout << "=== Day " << i << " ===\n";
		std::cout << plantObj1.name << ":" << " " << plantObj1.height << "cm" << "," << " " << plantObj1.age << " days old\n";
		std::cout << plantObj2.name << ":" << " " << plantObj2.height << "cm" << "," << " " << plantObj2.age << " days old\n";
		std::cout << plantObj3.name << ":" << " " << plantObj3.height << "cm" << "," << " " << plantObj3.age << " days old\n";
		plantObj1.height++;
		plantObj2.height++;
		plantObj3.height++;
		plantObj1.age++;
		plantObj2.age++;
		plantObj3.age++;
		i++;
	}
	std::cout << "Growth this week: " << plantObj1.height - startheight1 << "cm\n";
}

int	main(void)
{
	ft_plant_growth();
}