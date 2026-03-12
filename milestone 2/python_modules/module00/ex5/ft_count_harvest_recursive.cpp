#include <iostream>

void ft_count_harvest_recursive(int day, int i) 
{
	if (i >= day)
	{
		std::cout << "Day " << day << "\n";
		ft_count_harvest_recursive(day + 1, i);
	}
	else if (i <= day)
		std::cout << "Harvest time!\n";
}

int main(void)
{
	int input;
	int day;

	std::cout << "Days until harvest: ";
	std::cin >> input;

	ft_count_harvest_recursive(1, input);
    return 0;
}