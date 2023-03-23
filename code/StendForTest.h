#pragma once
#include "Engine.h"
#include "InternalCombustionEngine.h"
#include <thread>
#include <memory>

class StendForTest
{
	double workedTime = 0.0;
	std::shared_ptr <Engine> test_engine;
	void stend();

public:
	StendForTest(std::shared_ptr <Engine> eng);
	~StendForTest();
	double getTimeHasWorked();
};


