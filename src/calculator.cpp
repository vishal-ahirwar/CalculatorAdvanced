#include <calculator.h>
#include <time.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <functional>
#define EQ_LEN 5

Calculator::Calculator() : user_input{}, result{}
{
    std::cout << std::setw(20) << "Welcome to the calc Mastry :)\n";
    std::cout << "Objective :" << std::setw(20) << "Guess the result as quickly you can !that's it.\n";
    srand(time(NULL));
};

int Calculator::init()
{
    while (bQuit())
    {
        process(generateEquation());
    }
    return 0;
};

bool Calculator::bQuit() const
{
    std::cout << "Would you like to continue? [y|n]";
    char input{};
    std::cin >> input;
    return tolower(input) == 'y' ? true : false;
};

const std::vector<long int> Calculator::generateEquation()
{
    int len{rand() % EQ_LEN + 2};
    std::vector<long int> eq{};
    while (len > 0)
    {
        eq.push_back(rand() % 100);
        --len;
    };
    return eq;
};

void Calculator::process(const std::vector<long int> &eq)
{
    generateType();
    char character{};
    switch (type)
    {
    case E_OPERATION_TYPE::ADD:
        result = std::accumulate(eq.begin(), eq.end(), 0, std::plus<long int>());
        character = '+';
        break;
    case E_OPERATION_TYPE::SUB:
        // result = std::accumulate(eq.begin(),eq.end(),0,std::minus<long int>());
        result=[&]()->long int{auto out{eq[0]};for(int i=1;i<eq.size();++i){out-=eq[i];};return out;}();
        character = '-';
        break;
    case E_OPERATION_TYPE::MULTY:
        result = std::accumulate(eq.begin(), eq.end(), 1, std::multiplies<long int>());
        character = '*';
        break;
    };
    auto eq_len{eq.size()};
    std::cout << "What's the result of { ";
    for (size_t i = 0; i < eq_len; ++i)
    {
        std::cout << eq[i] << " ";
        if (i < eq_len - 1)
            std::cout << character << " ";
    };
    std::cout << "} : ";
    auto start{std::chrono::high_resolution_clock::now()};

    std::cin >> user_input;
    if (user_input == result)
    {
        std::cout << "Yes, it's correct answer :)\n";
    }
    else
    {
        std::cout << "Nope, it's not a correct answer :)\n";
        std::cout << "The asnwer is : " << result << "\n";
    };
    auto end{std::chrono::high_resolution_clock::now()};
    std::cout<<"time taken by you : "<<std::chrono::duration_cast<std::chrono::seconds>(end-start).count()<<"s\n";
};

void Calculator::generateType()
{
    switch (rand() % 3)
    {
    case 0:
        type = E_OPERATION_TYPE::ADD;
        break;
    case 1:
        type = E_OPERATION_TYPE::SUB;
        break;
    case 2:
        type = E_OPERATION_TYPE::MULTY;
        break;
    };
};
