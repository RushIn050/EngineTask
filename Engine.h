#pragma once

class Engine
{
public:
	virtual void EngineStart() = 0;
	virtual void EngineStop() = 0;
	virtual ~Engine() = 0 {};
	virtual void Working() = 0;
	virtual bool IsWorking() = 0;
	virtual void setWorking(bool condition) = 0;
	virtual double getTimeHasWorked() = 0;
	virtual double getEngineTemperature() = 0;
	virtual double getOverhatingTemperature() = 0;
};

