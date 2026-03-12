#include <iostream>

void	ft_count_harvest_iterative()
{
	int days_till_harvest, counter = 0;

	std::cout << "Days until harvest: ";
	std::cin >> days_till_harvest;
	while (counter < days_till_harvest)
	{
		counter++;
		std::cout << "Day " << counter << "\n";
	}
	std::cout << "Harvest time!\n";
}

int		main(void)
{
	ft_count_harvest_iterative();
	return 0;
}