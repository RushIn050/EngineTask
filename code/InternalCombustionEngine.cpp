#include "InternalCombustionEngine.h"
#include <windows.h>

InternalCombustionEngine::InternalCombustionEngine(double Tenvi)
{
	TEng = Tenvi;
	Tenv = Tenvi;
}

InternalCombustionEngine::~InternalCombustionEngine(){}


void InternalCombustionEngine::EngineStart()
{
	Working();
}


void InternalCombustionEngine::Working()
{
	double dt = 0.001, V_AatTheMoment = 0.0; //dt - малое приращение времени
	int current = 0, s = V.size(); // порядковый номер элемента массивов M и V
	setWorking(true);
	double M_current = M[current];
	Sleep(2000);
	while (WorkingStatus())
	{ //численное решение диффура методом эйлера

		double a = M_current / I; // вычисление ускорения
		V_AatTheMoment = V_AatTheMoment + (a * dt);
		Vh = (M_current * Hm) + (V_AatTheMoment * V_AatTheMoment * Hv);
		Vc = C * (Tenv - TEng);

		TEng = TEng + (C * (Vh + Vc)) * dt; // температура двигателя = значение прошлой итерации + изменение за время этой

		double V_multiplier = (V_AatTheMoment - V[current]) / (V[current + 1] - V[current]); // множитель кусочка зависимости M-V
		M_current = M[current] + (M[current + 1] - M[current]) * V_multiplier;


		if (current < s - 1)
		{
			if (V_AatTheMoment >= V[current + 1] && current < s - 2)
				++current;
		}

		workedTime += dt;
	}
}

void InternalCombustionEngine::EngineStop()
{
	setWorking(false);
}

bool InternalCombustionEngine::WorkingStatus()
{
	return working;
}

void InternalCombustionEngine::setWorking(bool condition)
{
	working = condition;
}

double InternalCombustionEngine::getTimeHasWorked()
{
	return workedTime;
}

double InternalCombustionEngine::getEngineTemperature()
{
	return TEng;
}

double InternalCombustionEngine::getOverhatingTemperature()
{
	return TOverhating;
}


