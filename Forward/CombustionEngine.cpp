#include "combustionEngine.h"
#include <iostream>


CombustionEngine::CombustionEngine(double momentOfInertia, const std::vector<std::pair<double, double>>& torqueDependenceOnRotationSpeed, double tempOverheat, 
	double torqueHeatingRate, double crankshaftRotationalHeatingRate, double coolingRate,double ambientTemperature):
	_momentOfInertia(momentOfInertia),
	_torqueDependenceOnRotationSpeed(torqueDependenceOnRotationSpeed),
	_tempOverheat(tempOverheat),
	_torqueHeatingRate(torqueHeatingRate),
	_crankshaftRotationalHeatingRate(crankshaftRotationalHeatingRate),
	_coolingRate(coolingRate),
	_ambientTemperature(ambientTemperature),
	_temp(ambientTemperature)
{}



void CombustionEngine::_updateTorque()
{
	size_t torqueDependenceOnRotationSpeedIndex = _torqueDependenceOnRotationSpeed.size() - 1;
	for (size_t i = 0; i < _torqueDependenceOnRotationSpeed.size(); i++)
	{
		if (_rotationSpeed < _torqueDependenceOnRotationSpeed[i].second)
		{
			torqueDependenceOnRotationSpeedIndex = i - 1;
			break;
		}
	}
	if (torqueDependenceOnRotationSpeedIndex >= _torqueDependenceOnRotationSpeed.size() - 1)
		return;

	const double linearInterpolationRate = 
		(_torqueDependenceOnRotationSpeed[torqueDependenceOnRotationSpeedIndex + 1].second - _rotationSpeed) / 
		(_torqueDependenceOnRotationSpeed[torqueDependenceOnRotationSpeedIndex + 1].second - _torqueDependenceOnRotationSpeed[torqueDependenceOnRotationSpeedIndex].second);

	_torque = _torqueDependenceOnRotationSpeed[torqueDependenceOnRotationSpeedIndex].first*(linearInterpolationRate) + 
		_torqueDependenceOnRotationSpeed[torqueDependenceOnRotationSpeedIndex + 1].first*(1 - linearInterpolationRate);
}

void CombustionEngine::simulate(double dt)
{
	_updateTorque();
	
	_rotationSpeed += (_torque / _momentOfInertia)*dt;
	_temp += (_torque * _torqueHeatingRate + _rotationSpeed * _rotationSpeed * _crankshaftRotationalHeatingRate) * dt - (_coolingRate * (_ambientTemperature - _temp))*dt;

}
