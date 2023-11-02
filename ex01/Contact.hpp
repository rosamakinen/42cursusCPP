/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:29:09 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 06:41:16 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact
{
	private:

	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	public:

	Contact(void);
	~Contact(void);
	std::string	getFirstName();
	std::string	getLastName ();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();
	void		setFirstName(std::string input);
	void		setLastName(std::string input);
	void		setNickName(std::string input);
	void		setPhoneNumber(std::string input);
	void		setDarkestSecret(std::string input);

};
#endif
