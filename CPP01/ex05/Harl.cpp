/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:40:17 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 09:17:34 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
	<< "I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
	<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;

}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
	<< "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain (std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*messages[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; levels[i] != "\0"; i++)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*messages[i])();
			break ;
		}
	}
}
