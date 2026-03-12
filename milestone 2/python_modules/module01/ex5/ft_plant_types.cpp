#include <iostream>
#include <string>
#include <cmath>

class Plant
{
  public:
	std::string name;
	int height, age;

	Plant(std::string n, int h, int a) : name(n), height(h), age(a)
	{
	}
	virtual void PrintInfo()
	{
		std::string class_name;
		class_name = typeid(*this).name();
		class_name.erase(class_name.begin());
		std::cout << name << " (" << class_name << "): " << height << "cm, " << age << " days, ";
	}
};

class Flower : public Plant
{
public:
    Flower(std::string n, int h, int a) : Plant(n, h, a) {}

    std::string color = "red";

    void PrintInfo() override
    {
        Plant::PrintInfo();
        std::cout << color << " color" << std::endl;
    }

    bool bloom(bool isBlooming)
    {
        if (isBlooming)
            std::cout << name << " is blooming beautifully!" << std::endl;
        else
            std::cout << name << " is not blooming yet!" << std::endl;
        return isBlooming;
    }
};


class Tree : public Plant
{
  public:
	Tree(std::string n, int h, int a) : Plant(n, h, a)
	{
	}
	float trunk_diameter = 50;
	void produce_shade()
	{
		std::cout << name << " provides " << (std::pow(trunk_diameter, 2) * M_PI)/ 4;
		std::cout << " square meters of shade" << "\n";
	}
	void PrintInfo() override
	{
		Plant::PrintInfo();
		std::cout << trunk_diameter << "cm diameter" << std::endl;
	}
};

class Vegetable : public Plant
{
  public:
	Vegetable(std::string n, int h, int a) : Plant(n, h, a)
	{
	}
	std::string harvest_season = "summer ";
	std::string nutritional_value = " is rich in vitamin C";
	void PrintInfo() override
	{
		Plant::PrintInfo();
		std::cout << harvest_season << "harvest" << std::endl;
	}
	void print_message()
	{
		std::cout << name << nutritional_value << std::endl; 
	}
};

int	main(void)
{
	std::cout << "=== Garden Plant Types ===" << "\n\n";
	Flower rose("Rose", 25, 30);
	Tree	oak("Oak", 500, 1825);
	Vegetable tomato("Tomato", 80, 90);

	rose.PrintInfo();
	rose.bloom(true);
	std::cout << "\n";
	oak.PrintInfo();
	oak.produce_shade();
	std::cout << "\n";
	tomato.PrintInfo();
	tomato.print_message();

	std::cout << "\n";
	return (0);
}