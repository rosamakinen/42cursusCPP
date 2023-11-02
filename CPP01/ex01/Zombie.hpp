/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:00:38 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/02 13:22:24 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class	Zombie
{
	private:

	std::string p_name;

	public:

	Zombie(void);
	~Zombie(void);
	void	announce();
	void	setName(std::string name);
	std::string getName(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif

