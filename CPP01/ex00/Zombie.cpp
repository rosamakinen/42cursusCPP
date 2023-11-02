/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:01:17 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 14:27:54 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie(void)
{
	std::cout << this->p_name << ": destructed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->p_name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

void	Zombie::setName(std::string name)
{
	this->p_name = name;
}

std::string Zombie::getName(void)
{
	return(this->p_name);
}
