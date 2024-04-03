#include "BitcoinExchange.hpp"

bool checkForLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

bool isValidDate(std::string date)
{
	std::tm  *tm = nullptr;
	std::istringstream stream(date);

	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = tm->tm_year;
	if (checkForLeapYear(year) == true)
		months[1] = 29;
	
	stream >> std::get_time(tm, "%F");
	if (stream.fail())
		return false;
	if (tm->tm_year < 0 || tm->tm_mon < 0 || tm->tm_mon > 11 || tm->tm_mday < 1 || tm->tm_mday > months[tm->tm_mon])
        return false;
	
	return true;
}

void BitcoinExchange::validateAndTransferDatabase()
{
	std::ifstream file("./data.csv");	

	if (file.is_open() == 0)
		throw std::invalid_argument("ERROR: csv file cannot be opened.");

	std::regex pattern(R"((\d{4}-\d{2}-\d{2}),(0|0.\d+|\d+.\d+))");
	std::string line;
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
			std::cerr << "ERROR: line '" << line << "' is formatted wrong" << std::endl;
	}
	file.close();
	
}

void BitcoinExchange::validateInputPrintOutput(std::string filename)
{
	std::ifstream file(filename);	

	if (file.is_open() == 0)
		throw std::invalid_argument("ERROR: input file cannot be opened.");

	std::regex pattern(R"(\d{4}-\d{2}-\d{2}) \| (0|0\.\d+|[1-9]\d{0,2}\.\d+|[1-9]\d{0,2})");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "input file does not following format: 'date | value' " << std::endl;
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
			isValidDate(date);
			calculateAndPrint(date, rate);
		}
		else if (match[2].compare("1000") == 0)
		{
			long double rate = stold(match[2].str());
			calculateAndPrint(match[1].str(), rate);
		}
		else
			std::cerr << "ERROR: line '" << match[1].str() << match[2].str() << "' is formatted wrong" << std::endl;
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
	validateAndTransferDatabase();
	validateInputPrintOutput(filename);
}
