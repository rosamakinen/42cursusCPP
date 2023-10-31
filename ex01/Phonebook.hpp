/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:17:12 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/31 09:32:56 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_SIZE 8

class	PhoneBook
{
	private:

	Contact	contacts[MAX_SIZE];
	std::string getUserInput(std::string prompt);
	//int	contactCount;

	public:

	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(int index);
	void	displayContacts(void);
};

#endif
