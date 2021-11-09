/*
 * @file light.hpp
 * @author @FLORET Somia
 * @brief sensor of light
 * @date 11/10/2021
 */

#include "light.hpp"

/**
 * @brief construct a light sensor
 */
LightSen::LightSen() : Sensor(8000, "Light", 1, 0) {}

/**
 * @brief construct a light sensor
 */
LightSen::~LightSen() {}

