#pragma once
#include <vector>
#include "engine.h"

class CombustionEngine final: public Engine
{
public:
	CombustionEngine(double momentOfInertia, 
		const std::vector<std::pair<double, double>> &torqueDependenceOnRotationSpeed,double tempOverheat, 
		double torqueHeatingRate, double crankshaftRotationalHeatingRate, double coolingRate, double ambientTemperature);
	
	virtual ~CombustionEngine() = default;

	void simulate(double dt) override;

	double getTemp() const override{  return _temp; }

	double getOverheatTemp() const override  {	return _tempOverheat;}
	
private:
	
	void _updateTorque();

	const double _tempOverheat;
	const double _ambientTemperature;
	const double _torqueHeatingRate;
	const double _crankshaftRotationalHeatingRate;
	const double _coolingRate;

	double _momentOfInertia{};
	double _torque{};
	double _rotationSpeed{};
	double _temp{};

	
	std::vector<std::pair<double, double>> _torqueDependenceOnRotationSpeed;
};

