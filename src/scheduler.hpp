/**
 * @file scheduler.hpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief scheduler class to manage the data sensors through the time
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <vector>
#include <list>
#include "sensor.hpp"
#include "server.hpp"

class Scheduler
{
public:

	Scheduler();

/**
 * @brief returns true if the time of the interval of the sensor is passed
 */
	template <typename T>
	bool checkT(T& sen)
		{
			if(((double) (clock() - sen.getClock()))*1000 /CLOCKS_PER_SEC  >= sen.getInterval())
		    {
				sen.setClock(clock());
			  	return true;
			}
			else
			{
				return false;
			}
		}
	virtual ~Scheduler();

private:

	Server server;

	LightSen lightSen;
	HumiditySen humiditySen;
	TemperatureSen temperatureSen;
	PressionSen pressionSen;
};

#endif /* SCHEDULER_H_ */
