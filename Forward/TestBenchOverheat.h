#pragma once
#include "TestBench.h"

class TestBenchOverheat : public TestBench
{
public:
	
	TestBenchOverheat() = default;
	virtual ~TestBenchOverheat() = default;

	void run(Engine * engine, double dt, double maxSimulationTime = 60*60) override;
};

