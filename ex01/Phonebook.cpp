/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:06 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/31 09:53:00 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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
	contacts[index].setPhoneNumber(this->getUserInput("Phone number "));
	contacts[index].setDirtySecret(this->getUserInput("Dirty secret: "));
}

std::string PhoneBook::getUserInput(std::string prompt)
{
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		if (input == "")
		{
			std::cout << "empty fields not accepted" << std::endl;
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
	while (i < 8)
	{
		std::string first = contacts[i].getFirstName();
		std::string last = contacts[i].getLastName();
		std::string nick = contacts[i].getNickName();

		if (first.compare("") == 0 && i == 0)
		{
			std::cout << "PHONEBOOK IS EMPTY, PLEASE ADD AT LEAST ONE CONTACT" << std::endl;
			break ;
		}
		std::cout << i + 1 << std::right << std::setw(10) << '|'
				  << first.substr(10) << std::left << '|'
				  << last.substr(10) << std::left << '|'
				  << nick.substr(10) << std::left << '|'
				  << std::endl;
		i++;
	}
}
