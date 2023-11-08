/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:20:19 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/07 13:30:28 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//input for the program is: (inputfile)filename, (to be overwritten)string1, (overwrited with)string2
#include "Sed.hpp"

static int input_check(std::ifstream &in_file, std::string string1)
{
	if (!in_file.is_open())
	{
		std::cout << "sorry pal, something went wrong with opening the file" << std::endl;
		return -1;
	}
	if (in_file.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "sorry pal, cannot handle an empty inputfile" << std::endl;
		in_file.close();
		return -1;
	}
	if (string1.compare("") == 0)
	{
		std::cout << "sorry pal, the string to replace needs to have some content in it" << std::endl;
		return -1;
	}
	return 0;
}

static int check_directory(char *path)
{
	struct stat fileStat;
	if (stat(path, &fileStat) == 0)
	{
		if (S_ISDIR(fileStat.st_mode))
		{
			std::cout << path << " sorry pal, is a directory." << std::endl;
			return -1;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (check_directory(argv[1]) == -1)
			return -1;
		std::ifstream	in_file;
		std::string		in_file_name = argv[1];
		in_file.open(in_file_name);
		if (input_check(in_file, argv[2]) == -1)
			return -1;
		std::string	content;
		std::getline(in_file, content, '\0');

		std::ofstream	new_file;
		std::string new_file_name(argv[1]);
		new_file_name.append(".replace");
		new_file.open(new_file_name);
		if (!new_file.is_open())
		{
			std::cout << "something went wrong with opening the file" << std::endl;
			return -1;
		}

		std::string	string1(argv[2]);
		std::string	string2(argv[3]);
		int idx;
		if (string1 != string2)
		{
			while ((idx = content.find(string1)) != -1)
			{
				content.erase(idx, string1.length());
				content.insert(idx, string2);
			}
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
