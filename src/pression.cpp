/*
 * @file pression.hpp
 * @author @FLORET Somia
 * @brief sensor of pressure
 * @date 11/10/2021
 */
#include "pression.hpp"

/**
 * @brief construct a pressure sensor
 */
PressionSen::PressionSen() : Sensor(7000, "Pressure", 1, 0.01){}

/**
 * @brief destroy a pressure sensor
 */
PressionSen::~PressionSen() {}


