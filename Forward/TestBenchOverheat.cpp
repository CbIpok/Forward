#include "TestBenchOverheat.h"
#include <ctime>
#include <iostream>

void TestBenchOverheat::run(Engine * engine, double dt , double maxSimulationTime)
{
	double time = 0;

	const double overheatTemp = engine->getOverheatTemp();

	for (size_t i = 0; i < maxSimulationTime/dt; i++)
	{
		engine->simulate(dt);
		time += dt;
		if (engine->getTemp() > engine->getOverheatTemp())
		{
			std::cout << "Engine overheated. " << time << " seconds have passed." << std::endl;
			return;
		}
	}

}
