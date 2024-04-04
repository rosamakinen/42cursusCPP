#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		BitcoinExchange bt;

		bt.CalculateBitcoinExchange(argv[1]);

		return 0;
	}

}
