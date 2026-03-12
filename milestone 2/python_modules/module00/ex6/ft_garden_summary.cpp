#include <iostream>
#include <string>

void	ft_garden_summary(void)
{
	int	plant_num;

	std::string garden_name;
	std::cout << "Enter garden name: ";
	std::getline(std::cin, garden_name);
	std::cout << "Enter number of plants: ";
	std::cin >> plant_num;
	std::cout << garden_name << " has " << plant_num << " plants growing well!\n";
}

int	main(void)
{
	ft_garden_summary();
	return (0);
}