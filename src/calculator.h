#ifndef CALC
#define CALC
#include <vector>

enum class E_OPERATION_TYPE
{
    ADD,
    SUB,
    MULTY,
};

class Calculator
{
private:
    long int user_input{};
    long int result{};
    E_OPERATION_TYPE type{};

public:
    Calculator();
    int init();

private:
    bool bQuit() const;
    const std::vector<long int> generateEquation();
    void process(const std::vector<long int> &);
    void generateType();
};
#endif