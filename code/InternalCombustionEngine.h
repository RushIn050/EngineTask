#pragma once
#include "Engine.h"
#include <vector>

class InternalCombustionEngine : public Engine
{
	double I{ 0.1 }; // Момент инерции двигателя
	std::vector<int> M{ 20, 75, 100, 105, 75, 0 };// Кусочно-линейная зависимость крутящего момента M-
	std::vector<int> V{ 0, 75, 150, 200, 250, 300 };// от скорости вращения коленвала V
	int TOverhating{ 110 };// Температура перегрева
	double Hm{ 0.01 };// Коэффициент зависимости скорости нагрева от крутящего момента
	double Hv{ 0.0001 };// Коэффициент зависимости скорости нагрева от скорости вращения коленвала
	double C{ 0.1 };// Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
	double Tenv{ 0.0 };
	double TEng = 0.0; //температура двигателя
	bool working = false;
	double Vh{ 0.0 };// Скорость нагрева двигателя
	double Vc{ 0.0 };// Скорость охлаждения двигателя
	double workedTime{ 0.0 };

	void Working() override;

public:

	InternalCombustionEngine(double Tenvi);
	~InternalCombustionEngine() override;
	void EngineStart() override;
	void EngineStop() override;
	bool WorkingStatus() override;
	void setWorking(bool condition) override;
	double getTimeHasWorked();
	double getEngineTemperature() override;
	double getOverhatingTemperature() override;
};
