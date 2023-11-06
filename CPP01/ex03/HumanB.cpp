/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:35:25 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 14:50:06 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : p_name(name), p_weapon(NULL)
{

}

HumanB::~HumanB()
{

}

std::string HumanB::getName()
{
	return this->p_name;
}

void HumanB::setName(std::string name)
{
	this->p_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->p_weapon = &weapon;
}

void	HumanB::attack()
{
	if (!this->p_weapon)
	{
		std::cout << this->p_name << " attacks with their bare fists" << std::endl;
		return ;
	}
	std::cout << this->p_name << " attacks with their " << p_weapon->getType() << std::endl;
}

