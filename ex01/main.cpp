/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:21:46 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/31 16:28:15 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	PhoneBook	babysFirstPhoneBook;
	std::string	input;
	int	i = 0;
	while (1)
	{
		std::cout << "PLEASE ENTER COMMAND TO EXECUTE (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "All righty, this was it then, bye bye!" << std::endl;
			exit (0);
		}
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "All righty, this was it then, bye bye!" << std::endl;
			break;
		}
		else if (input.compare("ADD") == 0)
		{
			if (i == MAX_SIZE)
				i = 0;
			babysFirstPhoneBook.addContact(i);
			i++;
		}
		else if (input.compare("SEARCH") == 0)
			babysFirstPhoneBook.displayContacts();
				//std::cout << "i guess here we would search" << std::endl;
	}
	return (0);
}
