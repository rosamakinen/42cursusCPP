/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:52:28 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 13:06:14 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *babysFirstZombie = newZombie("newZombie");

	babysFirstZombie->announce();
	randomChump("randomChump");
	delete babysFirstZombie;
	return (0);
}
