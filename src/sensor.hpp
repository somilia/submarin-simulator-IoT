/**
 * @file sensor.hpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief sensor class to manage all the sensor in general
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include <string>
#include <cmath>
#include <random>

#include <time.h>

template <class T>
class Sensor
{
public:

/**
 * @brief constructs a Sensor
 * @param interval configures interval of time for which the sensor will send data
 * @param name configures the name of the sensor
 * @param moy configures the mean for the normal distribution
 * @param ecartT configures the standard deviation for the normal distribution
 */
	Sensor<T>(float interval, std::string nom, float moy, float ecartT) : m_data(0), m_interval(interval), m_name(nom), m_clock(0), m_moyenne(moy), m_ecart_type(ecartT) {};

/**
 * @brief destroy the sensor
 */
	virtual ~Sensor(){}

/**
 * @brief affects a sensor characteristics to another one
 */
	Sensor<T>& operator=(const Sensor& sen)
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
	void setDataSensor()
	{
		this->m_data = aleaGenVal();
	}

 /**
 * @brief allows the access of the data into private part of the object by returning it
 */
	T getData() const
	{
		return this->m_data;
	}

/**
 * @brief allows the access of the name into private part of the object by returning it
 */
	std::string getNameSen() const
	{
		return this->m_name;
	}

/**
 * @brief allows the access of the interval into private part of the object by returning it
 */
	int getInterval() const
	{
		return m_interval;
	}

/**
 * @brief allows the access of the clock of the sensor
 */
	clock_t getClock() const
	{
			return m_clock;
	}

/**
 * @brief actualize the clock of the sensor in order to count until the interval is passed
 */
	void setClock(clock_t clock)
	{
		this->m_clock = clock;
	}

/**
 * @brief generates a float for the data sensor by using the normal distribution
 */
	T aleaGenVal()
	{
		if (this->getNameSen()=="Light")
		{
			srand(time(NULL));
			int nbGen=rand()%2+0;

			return nbGen;
		}
		else
		{
			const unsigned int seed = time(nullptr);
			std::default_random_engine engin {seed};
			std::normal_distribution<float> normal(this->m_moyenne, this->m_ecart_type);

			return normal(engin);
		}
	}

private:

	T m_data;
	int m_interval;
	std::string m_name;
	clock_t m_clock;
	float m_moyenne;
	float m_ecart_type;
};


#endif /* SENSOR_H_ */
