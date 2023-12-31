/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:35:56 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 07:35:59 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->p_type = name;
}

Weapon::~Weapon()
{

}

void	Weapon::setType(std::string type)
{
	this->p_type = type;
}

const std::string& Weapon::getType() const
{
	return this->p_type;
}
