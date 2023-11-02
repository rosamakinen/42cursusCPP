/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:12 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 08:51:36 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#define MAX_SIZE 8

class	PhoneBook
{
	private:

	Contact		contacts[MAX_SIZE];
	std::string	getUserInput(std::string prompt);
	std::string	truncateString(std::string input);
	void		displayHeader(void);
	void		printContact(Contact contact);

	public:

	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(int index);
	void	searchContact(void);
	void	displayContacts(void);
	void	phoneBookHeader(void);
};

#endif
