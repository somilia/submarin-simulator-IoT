/*
 * @file pression.hpp
 * @author @FLORET Somia
 * @brief sensor of pressure
 * @date 11/10/2021
 */

#ifndef PRESSION_HPP_
#define PRESSION_HPP_

#include "sensor.hpp"

class PressionSen : public Sensor<int>
{
public:
	PressionSen();
	virtual ~PressionSen();
};



#endif /* PRESSION_HPP_ */
