/**
 * @file sensor.cpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief sensor class to manage all the sensor in general
 */

#include <iostream>
#include <cmath>
#include <random>
#include "sensor.hpp"

/**
 * @brief constructs a Sensor
 * @param interval configures interval of time for which the sensor will send data
 * @param name configures the name of the sensor
 * @param moy configures the mean for the normal distribution
 * @param ecartT configures the standard deviation for the normal distribution
 */
Sensor::Sensor(float interval, std::string nom, float moy, float ecartT) : m_data(0), m_interval(interval), m_name(nom), m_clock(0), m_moyenne(moy), m_ecart_type(ecartT) {}

/**
 * @brief affects a sensor characteristics to another one
 */
Sensor& Sensor::operator=(const Sensor& sen)
{
	m_data = sen.m_data;
	m_interval = sen.m_interval;
	m_name = sen.m_name;
	m_clock = sen.m_clock;
	m_moyenne = sen.m_moyenne;
	m_ecart_type = sen.m_ecart_type;
	return *this;
}

/**
 * @brief sets the data sensor to save it
 */
void Sensor::setDataSensor()
{
	this->m_data = aleaGenVal();
}

/**
 * @brief allows the access of the data into private part of the object by returning it
 */
float Sensor::getData() const
{
	return m_data;
}

/**
 * @brief allows the access of the name into private part of the object by returning it
 */
std::string Sensor::getNameSen() const
{
	return m_name;
}

/**
 * @brief allows the access of the interval into private part of the object by returning it
 */
int Sensor::getInterval() const
{
	return m_interval;
}

/**
 * @brief returns true if the time of the interval of the sensor is passed
 */
bool Sensor::checkT()
{

	if(((double) (clock() - this->m_clock))*1000 /CLOCKS_PER_SEC  >= m_interval)
    {
		this->m_clock = clock();
	  	return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief generates a float for the data sensor by using the normal distribution
 */
float Sensor::aleaGenVal() const
{
	const unsigned int seed = time(nullptr);
	std::default_random_engine engin {seed};
	std::normal_distribution<float> normal(this->m_moyenne, this->m_ecart_type);

	return normal(engin);
}

/**
 * @brief destroy the sensor
 */
Sensor::~Sensor() {}

