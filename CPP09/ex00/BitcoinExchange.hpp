#pragma once

#include <iostream>
#include <ctime>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <regex>


class BitcoinExchange
{

	private:
		std::map<std::string, long double> _database;
		void validateAndTransferDatabase();
		void validateInputPrintOutput(std::string filename);
		void calculateAndPrint(std::string date, long double value);

	public:
		void CalculateBitcoinExchange(std::string filename);

};