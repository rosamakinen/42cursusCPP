#include "BitcoinExchange.hpp"

bool checkForLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

bool isValidDate(std::string date)
{
	std::tm t = {};
	std::istringstream stream(date);
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	stream >> std::get_time(&t, "%Y-%m-%d");
	if (stream.fail() == true)
	{
		std::cerr << "ERROR: bad input => " << date << std::endl;
		return false;
	}

	int year = t.tm_year;
	if (checkForLeapYear(year) == true)
		months[1] = 29;
	if ((t.tm_year + 1900) < 0 || t.tm_mon < 0 || t.tm_mon > 11 || t.tm_mday < 1 || t.tm_mday > months[t.tm_mon])
	{
		std::cerr << "ERROR: Bad input => " << date << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::validateAndTransferDatabase()
{
	std::ifstream file("./data.csv");

	if (file.is_open() == 0)
		throw std::invalid_argument("ERROR: csv file cannot be opened.");

	std::regex pattern("([0-9]{4}-[0-9]{2}-[0-9]{2}),(([0-9]*[.])?[0-9]+)");
	std::string line;
	getline(file, line);
	while(getline(file, line))
	{
		std::smatch match;
		if (std::regex_match(line, match, pattern))
		{
			std::string date = match[1].str();
			long double value = stold(match[2].str());
			_database[date] = value;
			continue;
		}
		else
		{
			std::cerr << "ERROR: wrong format" << std::endl;
		}
	}
	file.close();

}

void BitcoinExchange::validateInputPrintOutput(std::string filename)
{
	std::ifstream file(filename);

	if (file.is_open() == 0)
		throw std::invalid_argument("ERROR: input file cannot be opened.");

	std::regex pattern("([0-9]{4}-[0-9]{2}-[0-9]{2}) \\| ([0-9]{0,2}.+[0-9]{0,7}|[0-9]{0,4})");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		file.close();
		return;
	}
	while(getline(file, line))
	{
		std::smatch match;
		if (std::regex_match(line, match, pattern))
		{
			std::string date = match[1].str();
			long double rate = stold(match[2].str());
			if (rate > 1000.00)
			{
				std::cerr << "ERROR: value too big" << std::endl;
				continue ;
			}
			if (rate < 0)
			{
				std::cerr << "ERROR: not a positive number" << std::endl;
				continue ;
			}
			isValidDate(date);
			calculateAndPrint(date, rate);
		}
		else if (match[2].compare("1000") == 0)
		{
			long double rate = stold(match[2].str());
			calculateAndPrint(match[1].str(), rate);
		}
		else
			std::cerr << "ERROR: line '" << line << "' is formatted wrong" << std::endl;
	}
	file.close();
}

void BitcoinExchange::calculateAndPrint(std::string date, long double value)
{
	std::map<std::string, long double>::iterator iterator;

	iterator = _database.lower_bound(date);
	long double rate = iterator->second;
	std::cout << date << " => " << value << " = " << rate * value << std::endl;
}

void BitcoinExchange::CalculateBitcoinExchange(std::string filename)
{
	try
	{
		validateAndTransferDatabase();
		validateInputPrintOutput(filename);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &another)
{
	*this = another;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &another)
{
	if (this != &another)
	{
		this->_database = another._database;
	}
	return *this;
}
