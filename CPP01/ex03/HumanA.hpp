/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:35:20 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 10:42:03 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private:

	std::string p_name;
	Weapon &p_weapon;

	public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void	setName(std::string name);
	std::string getName(void);
	void	attack();
};

#endif
