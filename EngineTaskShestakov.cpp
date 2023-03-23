#include "Engine.h"
#include "InternalCombustionEngine.h"
#include "StendForTest.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

void PrintTimeTestResult(double res)
{
    std::cout << "двигатель перегрелся через:  " << res << " секунд\n";
}

void TimeTest(int Tenv)
{
    std::shared_ptr<InternalCombustionEngine> ICEng{ new InternalCombustionEngine(Tenv) };
    std::shared_ptr<StendForTest> eng{ new StendForTest(ICEng) };
    PrintTimeTestResult(eng->getTimeHasWorked());
}


int main()
{
    setlocale(LC_ALL, "Russian");

    std::string TEnvironment;
    int Tenv; //температура окружающей среды

    std::cout << "Введите температуру окружающей среды в градусах цельсия:\n";
    std::cin >> TEnvironment;


    try
    {
        Tenv = std::stoi(TEnvironment);
        
    }
    catch (const std::exception& exception)
    {
        std::cout << "Некорректное значение. Введите число:";
        std::cin >> Tenv;
    }

    if (Tenv <= -274)
    {
        std::cout << "Некорректное значение,температура не может быть ниже -274 градусов. Введите число:";
        std::cin >> Tenv;
    }
    TimeTest(Tenv);
    system("pause");
    return 0;
}


