#include "StendForTest.h"
#include "InternalCombustionEngine.h"
#include <windows.h>

StendForTest::StendForTest(std::shared_ptr<Engine> engine)
{
	test_engine = engine;
}

StendForTest::~StendForTest(){}

double StendForTest::getTimeHasWorked()
{
	stend();
	return workedTime;
}

void StendForTest::stend()
{
	if (test_engine != nullptr)
	{
		std::thread thForEngine(&Engine::EngineStart, test_engine);
		Sleep(2000);
		while (test_engine->WorkingStatus())
		{

			if (test_engine->getEngineTemperature() > test_engine->getOverhatingTemperature())
			{
				test_engine->EngineStop();
				workedTime = test_engine->getTimeHasWorked();
			}
		}
		thForEngine.detach();
	}
}


