#include <iostream>
#include <string>

void ft_garden_intro()
{
	std::string plant = "Rose";
	int			height = 25, age = 30;

	std::cout << "=== Welcome To My Garden ===\n";
	std::cout<< "\n";
	std::cout << "Plant: " << plant << "\n";
	std::cout << "Height: " << height << "cm\n";
	std::cout << "Age: " << age << " days\n";
	std::cout << "\n";
	std::cout << "=== End of Program ===\n";
}

int main(void)
{
	ft_garden_intro();
	return 0;
}