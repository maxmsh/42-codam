#include <iostream>

void	ft_water_reminder(void)
{
	int	days_since_watering;

	std::cout << "Days since last watering: ";
	std::cin >> days_since_watering;
	if (days_since_watering > 2)
		std::cout << "Water the plants!\n";
	else
		std::cout << "Plants are fine.\n";
}

int	main(void)
{
	ft_water_reminder();
	return 0;
}