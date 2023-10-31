/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:29:09 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/31 07:21:06 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Contact
{
	private:

	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	dirtySecret;

	public:

	Contact(void);
	~Contact(void);
	std::string	getFirstName();
	std::string	getLastName ();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDirtySecret();
	void	setFirstName(std::string input);
	void	setLastName(std::string input);
	void	setNickName(std::string input);
	void	setPhoneNumber(std::string input);
	void	setDirtySecret(std::string input);

};
#endif
