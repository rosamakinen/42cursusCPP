
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
//input for the program is: (inputfile)filename, (to be overwritten)string1, (overwrited with)string2

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream in_file(argv[1]);
		std::ofstream new_file;

		std::string string1(argv[2]);
		std::string string2(argv[3]);
		std::string content;

		if (!in_file.is_open())
		{
			std::cout << "something went wrong with opening the file" << std::endl;
			return -1;
		}

		std::getline(in_file, content, '\0');
		std::string new_file_name(argv[1]);
		new_file_name.append(".replace");
		new_file.open(new_file_name);
		if (!new_file.is_open())
		{
			std::cout << "something went wrong with opening the file" << std::endl;
			return -1;
		}

		int idx; 
		while ((idx = content.find(string1)) != -1)
		{
			content.erase(idx, string1.length());
			content.insert(idx, string2);
		}
		new_file << content;
		in_file.close();
		new_file.close();

		return 0;
	}
	else
		std::cout << "wrong arguments, run executable with name for new file, string1, string2" << std::endl;
	return -1;
}