/*
 * @file light.hpp
 * @author @FLORET Somia
 * @brief sensor of light
 * @date 11/10/2021
 */

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "sensor.hpp"

class LightSen : public Sensor<bool>
{
public:
	LightSen();
	virtual ~LightSen();
};



#endif /* LIGHT_HPP_ */
