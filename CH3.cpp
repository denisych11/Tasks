
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <algorithm>
#include <unordered_map>

inline void keep_window_open()
{
    std::cin.clear();
    std::cout << "Please enter a character to exit\n";
    char ch;
    std::cin >> ch;
    return;
}

inline void simple_error(std::wstring s)	// write ``error: s and exit program
{
    std::wcerr << "error: " << s << '\n';
    keep_window_open();		// for some Windows environments
    exit(1);
}


void Task1()
{
    std::wstring first_name{};
    std::wcout << L"Введите имя адресата" << std::endl;
    std::wcin >> first_name;
    std::wcout << L"Дорогой " << first_name << "," << std::endl;
    std::wcout << L"Как дела? " << std::endl << L"У меня все хорошо" << std::endl;

    std::wstring friend_name{};
    std::wcout << L"Введите имя друга" << std::endl;
    std::wcin >> friend_name;
    std::wcout << L"Давно ли ты встречал "<< friend_name<<"?" << std::endl;

    wchar_t friend_sex{ 0 };
    std::wcout << L"Введи значение m, если ваш друг - мужчина, и f - если женщина." << std::endl;
    std::wcin >> friend_sex;

    if('m' == friend_sex)
        std::wcout << L"Если ты увидишь "<< friend_name << L", пожалуйста, попроси его позвонить мне" << std::endl;
    else
        std::wcout << L"Если ты увидишь " << friend_name << L", пожалуйста, попроси её позвонить мне" << std::endl;
    
    int age{ 0 };
    std::wcout << L"Введите возраст адресата" << std::endl;
    std::wcin >> age;
    std::wcout << L"Я слышал, ты только что отметил день рождения и тебе исполнилось "<<age<< L" лет" << std::endl;
    if (age <= 0 || age >= 110)
        simple_error(L"Ты шутишь!");

    if (age < 12)
        std::wcout << L"На следующий год тебе исполнится " << age + 1 << L"лет" << std::endl;
    else if ( age == 17)
        std::wcout << L"В следующем году ты сможешь голосовать" << std::endl;
    else if (age > 70)
        std::wcout << L"Я надеюсь, что ты не скучаешь на пенсии" << std::endl;

    std::wcout << L"Искренне твой" << std::endl << std::endl << L"Денис" << std::endl;



}


void Task2()
{
    std::wcout << L"Введите кол-во км" << std::endl;
    double km{ 0 };
    std::wcin >> km;
    std::wcout << km << L"км = " << km * 1.609 << L"миль";
}

void Task3()
{
   // int double = 0;
   // int 9number = 9;
   // int two str = 2;
}

void Task4()
{
    int val1{ 0 }, val2{ 0 };
    std::wcout << L"Введите два целых числа" << std::endl;
    std::wcin >> val1 >> val2;
    if(val1 > val2)
        std::wcout << L"Max val = " <<  val1 << std::endl;
    else
        std::wcout << L"Max val = " << val2 << std::endl;
    std::wcout << L"Сумма = " << val1 + val2 << std::endl
        << L"Разность = " << val1 - val2 << std::endl
        << L"Произведение = " << val1 * val2 << std::endl;
    if (val2 != 0)
        std::wcout << L"Частное = " << val1 / val2 << std::endl;
    else
        std::wcout << L"Деление на ноль запрещенно " << std::endl;
}

void Task5()
{
    double val1{ 0 }, val2{ 0 };
    std::wcout << L"Введите два числа с плавающей точкой" << std::endl;
    std::wcin >> val1 >> val2;
    if (val1 > val2)
        std::wcout << L"Max val = " << val1 << std::endl;
    else
        std::wcout << L"Max val = " << val2 << std::endl;
    std::wcout << L"Сумма = " << val1 + val2 << std::endl
        << L"Разность = " << val1 - val2 << std::endl
        << L"Произведение = " << val1 * val2 << std::endl;
    if (val2 != 0)
        std::wcout << L"Частное = " << val1 / val2 << std::endl;
    else
        std::wcout << L"Деление на ноль запрещенно " << std::endl;
}

void Task6()
{
    std::wcout << L"Введите 3 целых числа" << std::endl;
    int val1{ 0 }, val2{ 0 }, val3{ 0 };
    std::wcin >> val1 >> val2 >> val3;
    while (val1 > val2 || val2 > val3)
    {
        if (val1 > val2)
        {
            val1 += val2;
            val2 = val1 - val2;
            val1 = val1 - val2;
        }
        if (val2 > val3)
        {
            val2 ^= val3;
            val3 ^= val2;
            val2 ^= val3;
        }
    }
    std::wcout << val1 << " " << val2 << " " << val3 << std::endl;
    /*std::vector<int> v;
    v.reserve(3);
    std::wcin >> v[0] >> v[1] >> v[2];
    std::sort(v.begin(), v.end());
    for (auto& a : v)
    {
        std::wcout << a << L" ";
    }
    std::wcout << std::endl;*/
}


void Task7()
{
    std::wcout << L"Введите 3 строки" << std::endl;
    std::wstring val1{}, val2{}, val3{};
    std::wcin >> val1 >> val2 >> val3;
    while (val1 > val2 || val2 > val3)
    {
        std::wstring temp{};
        if (val1 > val2)
        {
            temp = val2;
            val2 = val1;
            val1 = temp;
        }
        if (val2 > val3)
        {
            std::swap(val2, val3);
        }
    }
    std::wcout << val1 << " " << val2 << " " << val3 << std::endl;
}

void Task8()
{
    std::wcout << L"Введите целое число" << std::endl;
    int val1{ 0 };
    std::wcin >> val1;
    std::wcout << L"Число " << val1 << L" является ";
    if (val1 % 2 == 0)
        std::wcout << L"четным" << std::endl;
    else
        std::wcout << L"нечетным" << std::endl;

}

void Task9()
{
    std::unordered_map<std::wstring, int> uMap = {
        {L"нуль", 0 },
        {L"один", 1 },
        {L"два", 2 },
        {L"три", 3 },
        {L"четыре", 4 },
        {L"пять", 5 },
        {L"шесть", 6 },
        {L"семь", 7 },
        {L"восемь", 8 },
        {L"девять", 9 }};

    std::wstring num{};
    std::wcout << L"Введите цифру прописью" << std::endl;
    std::wcin >> num;
    const auto res = uMap.find(num);
    if (res == uMap.end())
        std::wcout << L"Я не знваю такого числа" << std::endl;
    else
        std::wcout << uMap[num] << std::endl;
}

void Task10()
{
    std::wcout << L"Введите операцию и два числа" << std::endl;
    std::wstring operation{};
    double val1, val2;
    std::wcin >> operation >> val1 >> val2;
    if(operation == L"+" || operation == L"plus")
        std::wcout << L"Sum " << val1 + val2 << std::endl;

    else if(operation == L"-" || operation == L"minus")
        std::wcout << L"Dif " << val1 - val2 << std::endl;

    else if(operation == L"*" || operation == L"mul")
        std::wcout << L"Mul " << val1 * val2 << std::endl;

    else if (operation == L"/" || operation == L"div")
    {
        if( val2 != 0)
            std::wcout << L"Div " << val1 / val2 << std::endl;
        else
            std::wcout << L"Деление на ноль"  << std::endl;
    }
}

void Task11()
{
    int oneC{ 0 }, fiveC{ 0 }, tenC{ 0 }, twentC{ 0 }, fiftyC{ 0 };
    std::wcout << L"Сколько у вас одноцентовых монет?" << std::endl;
    std::wcin >> oneC;
    std::wcout << L"Сколько у вас пятицентовых монет?" << std::endl;
    std::wcin >> fiveC;
    std::wcout << L"Сколько у вас десятицентовых монет?" << std::endl;
    std::wcin >> tenC;
    std::wcout << L"Сколько у вас двадцатипятицентовых монет?" << std::endl;
    std::wcin >> twentC;
    std::wcout << L"Сколько у вас пятидесятицентовых монет?" << std::endl;
    std::wcin >> fiftyC;

    if (oneC == 1)
        std::wcout << L"У вас 1 одноцентовая монета" << std::endl;
    else if(oneC == 2 || oneC == 3 || oneC == 4)
        std::wcout << L"У вас " << oneC<<L" одноцентовые монеты" << std::endl;
    else 
        std::wcout << L"У вас " << oneC << L" одноцентовых монет" << std::endl;

    if (fiveC == 1)
        std::wcout << L"У вас 1 пятицентовая монета" << std::endl;
    else if (fiveC == 2 || fiveC == 3 || fiveC == 4)
        std::wcout << L"У вас " << fiveC << L" пятицентовые монеты" << std::endl;
    else
        std::wcout << L"У вас " << fiveC << L" пятицентовых монет" << std::endl;

    if (tenC == 1)
        std::wcout << L"У вас 1 десятицентовая монета" << std::endl;
    else if (tenC == 2 || tenC == 3 || tenC == 4)
        std::wcout << L"У вас " << tenC << L" десятицентовые монеты" << std::endl;
    else
        std::wcout << L"У вас " << tenC << L" десятицентовых монет" << std::endl;

    if (twentC == 1)
        std::wcout << L"У вас 1 двадцатипятицентовая монета" << std::endl;
    else if (twentC == 2 || twentC == 3 || twentC == 4)
        std::wcout << L"У вас " << twentC << L" двадцатипятицентовые монеты" << std::endl;
    else
        std::wcout << L"У вас " << twentC << L" двадцатипятицентовых монет" << std::endl;

    if (fiftyC == 1)
        std::wcout << L"У вас 1 пятидесятицентовая монета" << std::endl;
    else if (fiftyC == 2 || fiftyC == 3 || fiftyC == 4)
        std::wcout << L"У вас " << fiftyC << L" пятидесятицентовые монеты" << std::endl;
    else
        std::wcout << L"У вас " << fiftyC << L" пятидесятицентовых монет" << std::endl;

    int sumC = oneC + fiveC * 5 + tenC * 10 + twentC * 25 + fiftyC * 50;
    int doll = sumC / 100;
    sumC %= 100;

    if (doll == 1)
        std::wcout << L"У вас 1 доллар ";
    else if (doll == 2 || doll == 3 || doll == 4)
        std::wcout << L"У вас " << doll << L" доллара ";
    else
        std::wcout << L"У вас " << doll << L" долларов ";


    if (doll == 1)
        std::wcout << L"1 цент ";
    else if (doll == 2 || doll == 3 || doll == 4)
        std::wcout <<  doll << L" цента";
    else
        std::wcout << doll << L" центов";

}

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    Task11();

    return 0;
}
