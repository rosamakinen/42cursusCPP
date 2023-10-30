/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:29:25 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/30 13:42:13 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

void	Contact::setFirstName(std::string input)
{
	this->_firstName = input;
}

std::string Contact::getFirstName()
{
	return (this->_firstName);
}

void	Contact::setLastName(std::string input)
{
	this->_lastName = input;
}

std::string Contact::getLastName()
{
	return (this->_lastName);
}

void	Contact::setNickName(std::string input)
{
	this->_nickName = input;
}

std::string Contact::getNickName()
{
	return (this->_nickName);
}

void	Contact::setPhoneNumber(std::string input)
{
	this->_phoneNumber = input;
}

std::string Contact::getPhoneNumber()
{
	return (this->_phoneNumber);
}

void	Contact::setDirtySecret(std::string input)
{
	this->_dirtySecret = input;
}

std::string Contact::getDirtySecret()
{
	return (this->_dirtySecret);
}
