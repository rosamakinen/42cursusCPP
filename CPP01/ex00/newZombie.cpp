/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:47:36 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 11:03:47 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//allocated to heap
Zombie *newZombie(std::string name)
{
	Zombie *newZombie = new Zombie;
	newZombie->setName(name);
	return (newZombie);
}
