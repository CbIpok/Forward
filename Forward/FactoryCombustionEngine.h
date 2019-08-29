#pragma once
#include "FactoryEngine.h"

class FactoryCombustionEngine final : public FactoryEngine
{
public:
	
	FactoryCombustionEngine() = default;
	 virtual ~FactoryCombustionEngine() = default;
	 
	 std::unique_ptr<Engine> makeEngine(double ambientTemperature) override;
};

