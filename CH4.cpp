
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_map>

void Task1()
{
	double min{ 0 }, max{ 0 }, newNum{ 0 }, sum{ 0 };
	std::string units{};
	std::vector<double> v;
	int i{ 0 };
	std::cout << "Please enter 2 numbers" << std::endl;
	while (std::cin >> newNum >> units)
	{
		i++;
		if (units == "m")
		{
			std::cout << newNum << "m = " << newNum * 100 << "cm" << std::endl;
		}
		else if (units == "cm")
		{
			std::cout << newNum << "cm = " << newNum / 100 << "m" << std::endl;
			newNum /= 100;
		}
		else if (units == "in")
		{
			std::cout << newNum << "in = " << newNum * 2.54 << "cm" << std::endl;
			newNum = newNum * 2.54 / 100;
		}
		else if (units == "ft")
		{
			std::cout << newNum << "ft = " << newNum * 12 << "in" << std::endl;
			newNum = newNum * 12 * 2.54 / 100;
		}
		else
		{
			std::cout  << "Wrong unit of measure" << std::endl;	
			continue;
		}
		if (i == 1) min = max = newNum;
		max = newNum > max ? newNum : max;
		min = newNum < min ? newNum : min;
		sum += newNum;
		v.push_back(newNum);
	}
	std::cout << "The gratest number is " << max << std::endl;
	std::cout << "The smallest number is " << min << std::endl;
	std::cout << "The sum is " << sum << std::endl;
	std::sort(v.begin(), v.end());
	for (auto a : v)
	{
		std::cout << a << " ";
	}
}

void Task2()
{
	std::vector<double> temps;
	for (double temp; std::cin >> temp;)
		temps.push_back(temp);

	std::sort(temps.begin(), temps.end());
	int mid = (temps[temps.size() / 2] + temps[temps.size() / 2 + 1]) / 2;
	std::cout << "Median temperature is " << mid;
}

void Task3()
{
	std::vector<double> dist;
	for (double val; std::cin >> val;)
		dist.push_back(val);

	double sum{ 0 };
	for (auto a : dist)
		sum += a;

	std::cout << "Sum = " << sum << std::endl;
	std::sort(dist.begin(), dist.end());
	std::cout << "Min = " << dist[0] << std::endl;
	std::cout << "Max = " << dist[dist.size() -1 ] << std::endl;

	std::cout << "Aver = " << sum / dist.size() << std::endl;
}

void Task4()
{
	int min{ 1 }, max{ 100 };
	while (min != max)
	{
		std::cout << "Is your number less than or equal " << (max + min) / 2 << "?" << std::endl;
		std::cout << "y or n" << std::endl;
		std::string ans;
		std::cin >> ans;
		if (ans == "y")
			max = (max + min) / 2;
		else if(ans == "n")
			min = (max + min) / 2 + 1;

	}
	std::cout << "Your number is " << min << std::endl;
}

void Calcs(double num1, double num2, char sign)
{
	if (sign == '+')
		std::cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << std::endl;
	else if (sign == '-')
		std::cout << "The difference of " << num1 << " and " << num2 << " is " << num1 - num2 << std::endl;
	else if (sign == '*')
		std::cout << "The product of " << num1 << " and " << num2 << " is " << num1 * num2 << std::endl;
	else if (sign == '/')
	{
		if (num2 != 0)
			std::cout << "The quotient of " << num1 << " and " << num2 << " is " << num1 / num2 << std::endl;
		else
			std::cout << "Division by zero" << std::endl;
	}
}

void Task5()
{
	double num1{ 0 }, num2{ 0 };
	char sign;
	while (std::cin >> num1 >> num2 >> sign)
	{
		Calcs(num1, num2, sign);
	}
}

template < typename T >
int GetIndex(const std::vector<T>& numbers, const T& str, int i = 0)
{
	for (; i < numbers.size() && str != numbers[i]; i++)
	{ }
	return i;
}

void Task6()
{
	std::vector<std::string> numbers{ "zero","one","two","three","four","five","six","seven","eight","nine" };
	int num{ 0 };
	std::string str;
	while (std::cin >> num >> str)
	{
		std::cout << numbers[num] << std::endl;
		
		std::cout << GetIndex(numbers, str) << std::endl;
	}
}

void Task7()
{
	std::vector<std::string> numbers{ "zero","one","two","three","four","five","six","seven","eight","nine" };
	std::string str1, str2;
	char sign;
	while (std::cin >> str1 >> str2 >> sign)
	{
		int num1, num2;
		if (str1.size() == 1)
			num1 = (int)str1[0] - (int)'0';
		else
			num1 = GetIndex(numbers, str1);

		if (str2.size() == 1)
			num2 = (int)str2[0] - (int)'0';
		else
			num2 = GetIndex(numbers, str2);

		Calcs(num1, num2, sign);
	}
}

void Task8()
{
	for (unsigned int cell = 1, corn = 1; corn < 2'000'000'000; cell++, corn *= 2)
	{
		std::cout << "Cells = " << cell << " Corns = " << corn << std::endl;
	}
}

void Task9()
{
	for (double cell = 1, corn = 1;  cell <= 64; cell++, corn *= 2)
	{
		std::cout << "Cells = " << cell << " Corns = " << corn << std::endl;
	}
}

void Task10()
{
	char player{};
	std::vector<char> v {'p', 'r', 's'};
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> gener(0,2);

	while (std::cin >> player)
	{
		char comp = v[gener(random_engine)];
		switch (player)
		{
		case 'p':
			if (comp == 'p')
				std::cout << "Draw" << std::endl;
			else if(comp == 'r')
				std::cout << "You won" << std::endl;
			else if (comp == 's')
				std::cout << "You lose" << std::endl;
			break;
		case 'r':
			if (comp == 'r')
				std::cout << "Draw" << std::endl;
			else if (comp == 's')
				std::cout << "You won" << std::endl;
			else if (comp == 'p')
				std::cout << "You lose" << std::endl;
			break;
		case 's':
			if (comp == 's')
				std::cout << "Draw" << std::endl;
			else if (comp == 'p')
				std::cout << "You won" << std::endl;
			else if (comp == 'r')
				std::cout << "You lose" << std::endl;
			break;
		}
	}
}

void Task11()
{
	std::vector<int> primes{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
	std::vector<int> results;
	for (int i = 2; i <= 100; i++)
	{
		bool isPrime = true;
		if (i != 2 && (i % 2 == 0))
			continue;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
				isPrime = false;
		}
		if (isPrime)
			results.push_back(i);
	}
	for (int i = 0; i < results.size(); i++)
	{
		std::cout << "results = " << results[i] << "  |  primes = " << primes[i] << std::endl;
	}
}

void Task12()
{
	int max{ 0 };
	std::cout << "Enter max value" << std::endl;
	std::cin >> max;
	std::vector<int> results;
	for (int i = 2; i <= max; i++)
	{
		bool isPrime = true;
		if ((i % 2 == 0) && i != 2  )
			continue;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
				isPrime = false;
		}
		if (isPrime)
			results.push_back(i);
	}
	for (int i: results)
	{
		std::cout << "results = " << i << std::endl;
	}
}



void Task13()
{
	std::vector<int> results;
	for (int i = 2; i <= 100; i++)
	{
		results.push_back(i);
	}
	for (int i = 0; i < results.size() / 2; i++)
	{
		for (int j = i + 1; j < results.size(); j++)
		{
			if (results[j] % results[i] == 0)
				results.erase(results.begin() + j);
		}
	}

	for (int i : results)
	{
		std::cout << "results = " << i << std::endl;
	}
}

void Task14()
{
	int max{ 0 };
	std::cout << "Enter max value" << std::endl;
	std::cin >> max;

	std::vector<int> results;
	for (int i = 2; i <= max; i++)
	{
		results.push_back(i);
	}
	for (int i = 0; i < results.size() / 2; i++)
	{
		for (int j = i + 1; j < results.size(); j++)
		{
			if (results[j] % results[i] == 0)
				results.erase(results.begin() + j);
		}
	}

	for (int i : results)
	{
		std::cout << "results = " << i << std::endl;
	}
}

void Task15()
{

	int max{ 0 };
	std::cout << "Enter the number of numbers you need" << std::endl;
	std::cin >> max;

	std::vector<int> results;
	int num{ 2 };

	while (results.size() < max)
	{
		bool isPrime = true;
		if ((num % 2 != 0) || num == 2)
		{
			for (int j = 2; j <= num / 2; j++)
			{
				if (num % j == 0)
					isPrime = false;
			}
			if (isPrime)
				results.push_back(num);
		}
		num++;
	}

	for (int i : results)
	{
		std::cout << "results = " << i << std::endl;
	}
}

void Task16()
{
	std::vector<int> v;
	int num{ 0 };
	while (std::cin >> num)
	{
		v.push_back(num);
	}
	std::unordered_map<int, int> uMap;
	for (auto a : v)
	{
		uMap[a]++;
	}
	auto cur = uMap.begin()->first;
	for (auto a : uMap)
	{
		if (a.second > uMap[cur])
			cur = a.first;
	}
	std::cout << cur << std::endl;
}


void Task17()
{
	std::vector<std::string> v;
	std::string str{};
	while (std::cin >> str)
	{
		v.push_back(str);
	}
	std::sort(v.begin(), v.end());
	std::string min = v[0];
	std::string max = v[v.size() -1];

	std::unordered_map<std::string, int> uMap;
	for (auto a : v)
	{
		uMap[a]++;
	}
	auto cur = uMap.begin()->first;
	for (auto a : uMap)
	{
		if (a.second > uMap[cur])
			cur = a.first;
	}
	std::cout <<"Min = " << min << std::endl;
	std::cout <<"Max = " << max << std::endl;
	std::cout <<"Mod = " << cur << std::endl;
}

void Task18()
{
	double a, b, c;
	while (std::cin >> a >> b >> c)
	{
		if (a == 0)
		{
			std::cout << "x = " << -c/b<< std::endl;
			continue;
		}
		double D = b * b - 4 * a * c;
		double x1, x2;
		if (D > 0)
		{
			x1 = (sqrt(D) - b) / 2 * a;
			x2 = (-sqrt(D) - b) / 2 * a;
			std::cout << "x1 = " << x1 << std::endl;
			std::cout << "x2 = " << x2 << std::endl;
		}
		else if (D == 0)
		{
			x1 = -b / 2 * a;
			std::cout << "x = " << x1 << std::endl;
		}
		else
			std::cout << "No equation roots"  << std::endl;			
	}
}

void Task19()
{
	std::vector<std::string> names;
	std::vector<int> scores;
	std::string name{};
	int score{ 0 };
	while (std::cin >> name >> score)
	{
		if (name == "NoName" && score == 0)
			break;
		names.push_back(name);
		scores.push_back(score);
	}
	bool isUniq = true;
	for (int i = 0; i < names.size() -1; i++)
	{
		for (int j = i + 1; j < names.size(); j++)
		{
			if (names[i] == names[j])
				isUniq = false;
		}
	}
	if (!isUniq)
		std::cout << "Error. Name entered twice" << std::endl;
	else
	{
		for (int i = 0; i < names.size(); i++)
		{
			std::cout << "Name: " << names[i] << " Score: " << scores[i] << std::endl;
		}
	}

	std::cout <<"Enter name or stop"<< std::endl;
	while (std::cin >> name)
	{
		if (name == "stop")
			break;
		int index = GetIndex(names, name);
		if (index == names.size())
			std::cout << "Name not found" << std::endl;
		else
		{
			std::cout <<  "Score: " << scores[index] << std::endl;
		}
	}

	std::cout << "Enter score" << std::endl;
	while (std::cin >> score)
	{
		int index = GetIndex(scores, score);
		if (index == names.size())
			std::cout << "Points not found" << std::endl;
		else
		{
			std::cout << "Name: " << names[index] << std::endl;
			while (index < scores.size())
			{
				index = GetIndex(scores, score, index + 1);
				if(index != names.size())
					std::cout << "Name: " << names[index] << std::endl;
			}
		}
	}
}

int main()
{
	Task19();
}