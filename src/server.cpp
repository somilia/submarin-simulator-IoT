/**
 * @file server.hpp
 * @author FLORET Somia
 * @date 11/10/2021
 * @brief allow to receive and/or save data sensors into the console and/or log file
 */

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <time.h>

#include "server.hpp"

using namespace std;

/**
 * @brief Construct a Server
 * @param m_consoleActivation if true print the data into the console
 * @param m_logActivation if true write data sensor into the log file
 */
Server::Server() : m_consoleActivation(1), m_logActivation(1) {}

/**
 * @brief destroy a server
 */
Server::~Server() {}

Server& Server::operator=(const Server& serv)
{
	m_consoleActivation = serv.m_consoleActivation;
	m_logActivation = serv.m_logActivation;
	return *this;
}

/**
 * @brief verify if the console/log activation is enabled and then execute it
 * @param m_consoleActivation if true print the data into the console
 * @param m_logActivation if true write data sensor into the log file
 */
void Server::dataRcv(const Sensor& sen)
{
	if (this->m_consoleActivation)
	{
		this->consoleWrite(sen);
	}
	if (this->m_logActivation)
	{
		this->fileWrite(sen);
	}
}

/**
 * @brief write the data sensor into the log file
 * @param sensor
 */
void Server::fileWrite(const Sensor sen)
{
	std::string nomFichier = "./Logs/";
	nomFichier.append(sen.getNameSen());
	nomFichier.append(".txt");

	ofstream leFlux(nomFichier.c_str(), ios::app);

	if(leFlux)
	{
		time_t secondes;
		struct tm instant;
		time(&secondes);
		instant=*localtime(&secondes);

		leFlux << instant.tm_mday << "/" << instant.tm_mon+1 << " | " << instant.tm_hour << ":" << instant.tm_min << ":" << instant.tm_sec << " : " << sen.getData() << endl;
	}
	else
	{
	    cout << "ERREUR" << endl;
	}
}

/**
 * @brief write the data sensor into the console
 * @param sensor
 */
void Server::consoleWrite(const Sensor sen)
{
	time_t secondes;
	struct tm instant;

	time(&secondes);
	instant=*localtime(&secondes);

	printf("%d/%d | %d:%d:%d\n", instant.tm_mday, instant.tm_mon+1, instant.tm_hour, instant.tm_min, instant.tm_sec);
	cout << "Capteur " << sen.getNameSen() << " : " << sen.getData() << endl;

}









