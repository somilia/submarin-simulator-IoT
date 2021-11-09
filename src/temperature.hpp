/*
 * @file temperature.hpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief sensor of temperature
 */

#ifndef TEMPERATURE_HPP_
#define TEMPERATURE_HPP_

#include "sensor.hpp"

class TemperatureSen : public Sensor<float>
{
public:
	TemperatureSen();
	virtual ~TemperatureSen();
};



#endif /* TEMPERATURE_HPP_ */
