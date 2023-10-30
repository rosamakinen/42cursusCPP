/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:29:09 by rmakinen          #+#    #+#             */
/*   Updated: 2023/10/30 10:52:18 by rmakinen         ###   ########.fr       */
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

	Contact( void );
	~Contact( void );
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_dirtySecret;

	public:

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
