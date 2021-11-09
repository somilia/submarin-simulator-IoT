/*
 * @file humidity.hpp
 * @author @FLORET Somia
 * @brief sensor of humidity
 * @date 11/10/2021
 */

#ifndef HUMIDITY_HPP_
#define HUMIDITY_HPP_

#include "sensor.hpp"

class HumiditySen : public Sensor<float>
{
public:
	HumiditySen();
	virtual ~HumiditySen();
};



#endif /* HUMIDITY_HPP_ */
