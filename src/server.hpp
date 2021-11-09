/**
 * @file server.hpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief allow to receive and/or save data sensors into the console and/or log file
 */

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include "temperature.hpp"
#include "humidity.hpp"
#include "light.hpp"
#include "pression.hpp"


class Server
{
public:

/**
 * @brief Construct a Server
 * @param m_consoleActivation if true print the data into the console
 * @param m_logActivation if true write data sensor into the log file(
 */
	Server() : m_consoleActivation(1), m_logActivation(1) {}

	/**
	 * @brief destroy a server
	 */
	virtual ~Server()
	{}

	Server& operator=(const Server& serv)
	{
		m_consoleActivation = serv.m_consoleActivation;
		m_logActivation = serv.m_logActivation;
		return *this;
	}

/**
 * @brief verify if the console/log activation is enabled and then execute it
 * @param data of the sensor
 * @param name of the sensor
 */
	template <typename T>
	void dataRcv(const T p_data, std::string p_name) {
		if (this->m_consoleActivation)
			{
				this->consoleWrite(p_data, p_name);
			}
			if (this->m_logActivation)
			{

				this->fileWrite(p_data, p_name);
			}
	};
/**
 * @brief write the data sensor into the log file
 * @param data of the sensor
 * @param name of the sensor
 */
	template <typename T>
	void fileWrite(const T p_data, std::string p_name) {
		std::string nomFichier = "./Logs/";
			nomFichier.append(p_name);
			nomFichier.append(".txt");

			std::ofstream leFlux(nomFichier.c_str(), std::ios::app);

			if(leFlux)
			{
				time_t secondes;
				struct tm instant;
				time(&secondes);
				instant=*localtime(&secondes);

				leFlux << instant.tm_mday << "/" << instant.tm_mon+1 << " | " << instant.tm_hour << ":" << instant.tm_min << ":" << instant.tm_sec << " : " << p_data << std::endl;
			}
			else
			{
			    std::cout << "ERREUR" << std::endl;
			}
	};

/**
 * @brief write the data sensor into the console
 * @param data of the sensor
 * @param name of the sensor
 */
	template <typename T>
	void consoleWrite(const T p_data, std::string p_name) {
		time_t secondes;
			struct tm instant;

			time(&secondes);
			instant=*localtime(&secondes);

			printf("%d/%d | %d:%d:%d\n", instant.tm_mday, instant.tm_mon+1, instant.tm_hour, instant.tm_min, instant.tm_sec);
			std::cout << "Capteur " << p_name << " : " << p_data << std::endl;

	};

private:

	bool m_consoleActivation;
	bool m_logActivation;
};

#endif /* SERVER_HPP_ */
