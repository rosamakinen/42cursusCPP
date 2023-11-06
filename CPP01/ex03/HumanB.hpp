/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:35:33 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 09:59:23 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:

	std::string p_name;
	Weapon *p_weapon;

	public:

	HumanB(std::string name);
	~HumanB(void);
	void	setName(std::string name);
	std::string getName();
	void	setWeapon(Weapon &weapon);
	void	attack();
};



#endif
