/*
 * @file humidity.hpp
 * @author FLORET Somia 
 * @date 11/10/2021
 * @brief sensor of humidity
 */

#include "humidity.hpp"
 
/**
 * @brief construct a humidity sensor
 */
HumiditySen::HumiditySen() : Sensor(1800, "Humidity", 10, 0.5){}

/**
 * @brief destroy a humidity Sensor
 */
HumiditySen::~HumiditySen() {}



