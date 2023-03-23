#include "StendForTest.h"
#include "InternalCombustionEngine.h"
#include <windows.h>





StendForTest::StendForTest(std::shared_ptr<Engine> engine)
{
	this->engine = engine;
}


StendForTest::~StendForTest()
{
}



double StendForTest::setTimeHasWorked()
{
	if (engine != nullptr)
	{
		std::thread thForEngine(&Engine::EngineStart, engine);
		thForEngine.detach();
		Sleep(3000); // 
		/*while (engine->IsWorking())
		{
			std::cout << "temp" << engine->getEngineTemperature() << engine->getOverhatingTemperature() << std::endl;
			if (engine->getEngineTemperature() > engine->getOverhatingTemperature())
			{
				engine->EngineStop();
				std::cout << engine->getEngineTemperature();
				return engine->getTimeHasWorked();
			}
		}*/ //не работает, IsWorking всегда отрицательна :(
		engine->EngineStop();
		return engine->getTimeHasWorked();
	}
	else
	  return 6;

}