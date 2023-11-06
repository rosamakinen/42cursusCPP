/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:35:14 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 09:52:19 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : p_name(name), p_weapon(weapon)
{

}

HumanA::~HumanA()
{

}

std::string HumanA::getName()
{
	return this->p_name;
}

void HumanA::setName(std::string name)
{
	this->p_name = name;
}

void	HumanA::attack()
{
	std::cout << this->p_name << " attacks with their " << p_weapon.getType() << std::endl;
}
