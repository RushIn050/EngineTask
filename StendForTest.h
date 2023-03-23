#pragma once
#include "Engine.h"
#include "InternalCombustionEngine.h"
#include <thread>
#include <memory>

class StendForTest
{
	std::shared_ptr <Engine> engine ;
public:
	StendForTest (std::shared_ptr <Engine> eng);
	~StendForTest();
	double setTimeHasWorked();
};

