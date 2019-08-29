#include "FactoryCombustionEngine.h"
#include "combustionEngine.h"
#include <vector>
#include<memory>

namespace
{
	const double momentOfInertia = 10;
	const std::vector<std::pair<double, double>> torqueDependenceOnRotationSpeed = { {20,0},{75,75},{100,150},{105,200},{75,250},{ 0, 300} };
	const double tempOverheat = 110;
	const double torqueHeatingRate = 0.01;
	const double crankshaftRotationalHeatingRate = 0.0001;
	const double coolingRate = 0.1;
}

std::unique_ptr<Engine> FactoryCombustionEngine::makeEngine(double ambientTemperature)
{	
	return std::make_unique<CombustionEngine>(momentOfInertia,torqueDependenceOnRotationSpeed,
		tempOverheat,torqueHeatingRate,crankshaftRotationalHeatingRate,coolingRate,ambientTemperature);
}
