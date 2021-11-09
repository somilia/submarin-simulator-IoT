/**
 * @file scheduler.cpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief scheduler class to manage the data sensors through the time
 */

#include <iostream>
#include <ctime>
#include <time.h>

#include "scheduler.hpp"


/**
 * @brief constructs the scheduler,
 * check if the time of each interval of the sensor is passed,
 * and execute the main functions of the program
 */
Scheduler::Scheduler() {

	Server serv;


	LightSen lightSen;
	HumiditySen humiditySen;
	TemperatureSen temperatureSen;
	PressionSen pressionSen;

	while(true)
	{

		if (checkT(temperatureSen))
		{
			temperatureSen.setDataSensor();

			serv.dataRcv(temperatureSen.getData(), temperatureSen.getNameSen());

		}
		if (checkT(humiditySen))
		{
			humiditySen.setDataSensor();

			serv.dataRcv(humiditySen.getData(), humiditySen.getNameSen());

		}
		if (checkT(lightSen))
		{
			lightSen.setDataSensor();

			serv.dataRcv(lightSen.getData(), lightSen.getNameSen());

		}
		if (checkT(pressionSen))
		{
			pressionSen.setDataSensor();

			serv.dataRcv(pressionSen.getData(), pressionSen.getNameSen());

		}
	}
}

/**
 * @brief destroy the scheduler
 */
Scheduler::~Scheduler() {}
