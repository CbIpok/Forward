#include "FactoryCombustionEngine.h"
#include "TestBenchOverheat.h"
#include <iostream>

int main()
{
	std::cout << "Enter ambient temperature: ";
	double ambientTemperature;
	std::cin >> ambientTemperature;

	auto factoryCombustionEngine = FactoryCombustionEngine();
	const auto engine = factoryCombustionEngine.makeEngine(ambientTemperature);
	auto testBenchOverheat = TestBenchOverheat();

	const double dt = 0.1;
	testBenchOverheat.run(engine.get(), dt);
	return 0;
}