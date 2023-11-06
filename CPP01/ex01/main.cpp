/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:52:28 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 14:21:13 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	{
		Zombie *zombies = zombieHorde(5, "zombieliini ");
		if (zombies)
			delete[] zombies;
	}
	{
		Zombie *zombies = zombieHorde(20, "zombieliini3 ");
		if (zombies)
			delete [] zombies;
	}
	{
		Zombie *zombies = zombieHorde(-5, "zombieliini1 ");
		if (zombies)
			delete[] zombies;
	}
	{
		Zombie *zombies = zombieHorde(std::numeric_limits<int>::max(), "zombieliini2 ");
		if (zombies)
			delete[] zombies;
	}
	{
		Zombie *zombies = zombieHorde(0, "zombieliini4 ");
		if (zombies)
			delete[] zombies;
	}
	return 0;
}
