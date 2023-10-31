/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:29:25 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/31 08:59:37 by rmakinen         ###   ########.fr       */
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
	this->firstName = input;
}

std::string Contact::getFirstName()
{
	return (this->firstName);
}

void	Contact::setLastName(std::string input)
{
	this->lastName = input;
}

std::string Contact::getLastName()
{
	return (this->lastName);
}

void	Contact::setNickName(std::string input)
{
	this->nickName = input;
}

std::string Contact::getNickName()
{
	return (this->nickName);
}

void	Contact::setPhoneNumber(std::string input)
{
	this->phoneNumber = input;
}

std::string Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

void	Contact::setDirtySecret(std::string input)
{
	this->dirtySecret = input;
}

std::string Contact::getDirtySecret()
{
	return (this->dirtySecret);
}
