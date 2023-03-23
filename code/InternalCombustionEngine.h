#pragma once
#include "Engine.h"
#include <vector>

class InternalCombustionEngine : public Engine
{
	double I{ 0.1 }; // ������ ������� ���������
	std::vector<int> M{ 20, 75, 100, 105, 75, 0 };// �������-�������� ����������� ��������� ������� M-
	std::vector<int> V{ 0, 75, 150, 200, 250, 300 };// �� �������� �������� ��������� V
	int TOverhating{ 110 };// ����������� ���������
	double Hm{ 0.01 };// ����������� ����������� �������� ������� �� ��������� �������
	double Hv{ 0.0001 };// ����������� ����������� �������� ������� �� �������� �������� ���������
	double C{ 0.1 };// ����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
	double Tenv{ 0.0 };
	double TEng = 0.0; //����������� ���������
	bool working = false;
	double Vh{ 0.0 };// �������� ������� ���������
	double Vc{ 0.0 };// �������� ���������� ���������
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
