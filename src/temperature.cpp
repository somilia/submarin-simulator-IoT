/*
 * @file temperature.hpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief sensor of temperature
 */

#include "temperature.hpp"

/**
 * @brief construct a temperature sensor
 */
TemperatureSen::TemperatureSen() : Sensor(1500, "Temperature", 20, 0.3){}

/**
 * @brief destroy a temperature sensor
 */
TemperatureSen::~TemperatureSen() {}

