#include <iostream>

void	ft_plant_age(void)
{
	int	plant_age;

	std::cout << "Enter plant age in days: ";
	std::cin >> plant_age;
	if (plant_age > 60)
		std::cout << "Plant is ready to harvest!\n";
	else
		std::cout << "Plant needs more time to grow.\n";
}

int	main(void)
{
	ft_plant_age();
	return 0;
}