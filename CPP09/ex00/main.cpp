#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		BitcoinExchange bt;

		bt.CalculateBitcoinExchange(argv[1]);
	}
	else
		std::cout << "ERROR: eyoo we need a inputfile, bubs" << std::endl;

	return 0;

}
