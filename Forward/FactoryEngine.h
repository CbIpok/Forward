#pragma once
#include "engine.h"
#include <memory>

class FactoryEngine
{
public:
	
	FactoryEngine() = default;
	virtual ~FactoryEngine() = default;
	
	virtual std::unique_ptr<Engine> makeEngine(double ambientTemperature) = 0;
};

