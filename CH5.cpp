#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>

double ctok(const double c)
{	
	if (-273.15 > c)
		return -1;
	return c + 273.15;
}

double ktoc(const double k)
{
	if (0 > k)
		return -274;
	return k - 273.15;
}

double ctof(const double c)
{
	if (-273.15 > c)
		return -460;
	return c * 9 / 5 + 32;
}

void Task2()
{
	double c = 0;
	while (std::cin >> c)
	{
		if (-273.15 > c)
			std::cout << "Error. Enter valid value" << std::endl;
	}
	double k = ctok(c);
	std::cout << k << std::endl;
}

void Task4()
{
	double c = 0;
	std::cin >> c;
	double k = ctok(c);
	if(k == -1)
		std::cout << "Error. Temperature below absolute zero" << std::endl;
	else
		std::cout << k << std::endl;
}


void Task5()
{
	double k = 0;
	std::cin >> k;
	double c = ktoc(k);
	if (c == -274)
		std::cout << "Error. Temperature below absolute zero" << std::endl;
	else
		std::cout << c << std::endl;
}


void Task6()
{
	double c = 0;
	std::cin >> c;
	double f = ctof(c);
	if (f == -460)
		std::cout << "Error. Temperature below absolute zero" << std::endl;
	else
		std::cout << f << std::endl;
}

void Task7()
{
	double a, b, c;
	try
	{
		std::cin >> a >> b >> c;
		double sqr = b * b - 4 * a * c;
		if (sqr < 0)
			throw "Discriminant less than zero";
		double x1 = (-b + sqrt(sqr)) / 2 * a;
		double x2 = (-b - sqrt(sqr)) / 2 * a;

		if (x1 != x2)
			std::cout << "x1= " << x1 << " x2= " << x2 << std::endl;
		else
			std::cout << "x= " << x1 << std::endl;
	}
	catch (...)
	{
		std::cerr << "Equation has no roots" << std::endl;
	}
}

void Task8()
{
	std::cout << "Enter number of values"  << std::endl;
	int n{ 0 };
	try
	{
		std::cin >> n;
		std::vector<double> v;
		std::cout << "Enter values or | to stop" << std::endl;
		std::string temp;
		while(true)
		{
			std::cin >> temp;
			if (temp == "|")
				break;
			v.push_back(std::stod(temp));
		}
		if (n > v.size())
			throw "Error";

		double res{ 0 };
		std::cout << "The sum of first " << n << " numbers (";
		for (int i = 0; i < n; i++)
		{
			std::cout << " " << v[i];
			res += v[i];
		}
		std::cout << ") is " << res << std::endl;
		std::vector<double> dif;
		for (int i = 1; i < v.size(); i++)
		{
			dif.push_back(v[i - 1] - v[i]);
		}
		for(auto a:dif)
		{
			std::cout << a <<" ";
		}

	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
	}
}

void Task11()
{
	int x{ 0 }, y{ 1 };
	while (x >=0 && y > 0)
	{
		std::cout << y << " ";
		y ^= x;
		x = y ^ x;
		y = (y ^ x) + x;
	}
}


void Task12()
{
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> gener(0, 9);
	std::vector<int> v(4);
	for(int i =0; i < 4; )
	{
		v[i] = gener(random_engine);
		bool doub = false;
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[i] == v[j])
				doub = true;
		}
		if (!doub)
			i++;
	}
	bool check{ false };
	std::cout << "The game has begun" << std::endl;
	while (!check)
	{
		std::string str;
		std::cin >> str;

		int bull{ 0 }, cow{ 0 };
		for (int i = 0; i < 4; i++)
		{
			auto temp = static_cast<int>(str[i]) - static_cast<int>('0');
			if (v[i] == temp)
				bull++;
			for (int j = 0; j < 4; j++)
			{
				temp = static_cast<int>(str[j]) - static_cast<int>('0');
				if (v[i] == temp && i != j)
					cow++;
			}
		}

		if (bull == 4)
		{
			check = true;
			std::cout << "You win" << std::endl;
		}
		else
		{

			std::cout << "Bulls: "<< bull<< " Cows: "<<cow << std::endl;
		}
	}
}

void Task13()
{
	bool restart{ true };
	while (restart)
	{
		Task12();
		std::cout << "Restart? y/n" << std::endl;
		char c;
		std::cin >> c;
		restart = c == 'y' ? true : false;
	}
}

void Task14()
{
	std::unordered_map<std::string, std::vector<int>> uMap;
	int errors{ 0 };
	while (true)
	{
		std::string str;
		int num{ 0 };
		std::cin >> str >> num;
		if (str == "Monday" || str == "monday" || str == "Mon")
		{
			uMap["Monday"].push_back(num);
		}
		else if (str == "Tuesday" || str == "tuesday" || str == "Tue")
		{
			uMap["Tuesday"].push_back(num);
		}
		else if (str == "Wednesday" || str == "wednesday" || str == "Wed")
		{
			uMap["Wednesday"].push_back(num);
		}
		else if (str == "Thursday" || str == "thursday" || str == "Thu")
		{
			uMap["Thursday"].push_back(num);
		}
		else if (str == "Friday" || str == "friday" || str == "Fri")
		{
			uMap["Friday"].push_back(num);
		}
		else if (str == "Saturday" || str == "saturday" || str == "Sat")
		{
			uMap["Saturday"].push_back(num);
		}
		else if (str == "Sunday" || str == "sunday" || str == "Sun")
		{
			uMap["Sunday"].push_back(num);
		}
		else if (str == "|")
			break;
		else
		{
			std::cout << "Incorrect day" << std::endl;
			errors++;
		}
	}
	for (auto a : uMap)
	{
		std::cout << a.first << std::endl;
		int sum{ 0 };
		for (auto b : a.second)
		{
			std::cout << b << " ";
			sum += b;
		}
		std::cout << std::endl << "Sum = " << sum << std::endl;
	}
	std::cout << std::endl << "Incorrect days: " << errors << std::endl;
}

int main()
{
	Task14();
	return 0;
}