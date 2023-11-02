/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:46:49 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 11:02:07 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//allocated to stack
void randomChump(std::string name)
{
	Zombie randomChump;
	randomChump.setName(name);
	randomChump.announce();
}
