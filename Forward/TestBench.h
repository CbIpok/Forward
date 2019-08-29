#pragma once
#include "engine.h"

class TestBench
{
public:
	
	TestBench() = default;
	virtual ~TestBench() = default;

	virtual void run(Engine * engine, double dt, double maxSimulationTime = 60*60) = 0;
};




