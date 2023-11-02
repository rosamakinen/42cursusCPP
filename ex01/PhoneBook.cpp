/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:06 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 08:47:40 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{

}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::addContact(int index)
{
	contacts[index].setFirstName(this->getUserInput("First name: "));
	contacts[index].setLastName(this->getUserInput("Last name: "));
	contacts[index].setNickName(this->getUserInput("Nick name: "));
	contacts[index].setPhoneNumber(this->getUserInput("Phone number: "));
	contacts[index].setDarkestSecret(this->getUserInput("Darkest secret: "));
}

std::string PhoneBook::getUserInput(std::string prompt)
{
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "All righty, this was it then, bye bye!" << std::endl;
			exit (0);
		}
		else if (input == "")
		{
			std::cout << "Empty fields not accepted!" << std::endl;
			continue;
		}
		else
			break ;
	}
	return (input);
}

void	PhoneBook::displayContacts()
{
	int i = 0;
	displayHeader();
	while (i < 8)
	{
		std::string first = contacts[i].getFirstName();
		std::string last = contacts[i].getLastName();
		std::string nick = contacts[i].getNickName();

		std::cout << std::setw(10) << i + 1 << std::left << '|'
				  << std::setw(10) << std::right << truncateString(first) << '|'
				  << std::setw(10) << std::right << truncateString(last) << '|'
				  << std::setw(10) << std::right << truncateString(nick) << '|'
				  << std::endl;
		i++;
	}
}

std::string PhoneBook::truncateString(std::string input)
{
	std::string result;

	if (input.length() > 10)
	{
		input.resize(9);
		input.insert(input.end(), 1, '.');
		return (input);
	}
	return (input);
}


void	PhoneBook::searchContact()
{
	std::string input = getUserInput("\nPLEASE ENTER INDEX TO DISPLAY");
	if (input.length() != 1 || input[0] < '1' || input[0] > '8')
	{
		std::cout << "Sorry, index you entered is not valid!" << std::endl;
		return ;
	}
	else
		std::cout << "\n** THE INDEX YOU REQUESTED IS:  " << input[0] << " **\n" << std::endl;
	int index = input[0] - '0';
	for (int i = 0; i < MAX_SIZE; i++)
		if (i == (index - 1))
			printContact(this->contacts[i]);
}

void	PhoneBook::printContact(Contact contact)
{
	std::string name = contact.getFirstName();
	std::string last = contact.getLastName();
	std::string nick = contact.getNickName();
	std::string phone = contact.getPhoneNumber();
	std::string secret = contact.getDarkestSecret();

	std::cout << "FIRST NAME:      " << name << std::endl;
	std::cout << "LAST NAME:       " << last << std::endl;
	std::cout << "NICKNAME:        " << nick << std::endl;
	std::cout << "PHONENUMBER:     " << phone << std::endl;
	std::cout << "DARKEST SECRET:  " << secret << std::endl << std::endl;
}

void	PhoneBook::phoneBookHeader()
{
	std::cout << "\n***************************" << std::endl;
	std::cout << "***  P H O N E B O O K  ***" << std::endl;
	std::cout << "***************************\n" << std::endl;
}

void	PhoneBook::displayHeader(void)
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "index" << std::right << '|'
				  << std::setw(10) << std::right << "first name" << '|'
				  << std::setw(10) << std::right << "last name" << '|'
				  << std::setw(10) << std::right << "nickname" << '|'
				  << std::endl;
}
