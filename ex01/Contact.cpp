/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:29:25 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/30 10:54:41 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Contact::setFirstName(std::string input)
{
	this->_firstName = input;
}

std::string Contact::getFirstName()
{
	return (this->_firstName);
}
