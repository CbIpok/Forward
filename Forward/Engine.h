#pragma once

class Engine
{
public:
	Engine() = default;
	virtual ~Engine() = default;
	
	virtual void simulate(double dt) = 0;

	virtual double getTemp() const= 0;

	virtual double getOverheatTemp() const = 0;
};

