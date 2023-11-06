/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:36:07 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 07:36:09 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
	private:

	std::string p_type;

	public:

	Weapon(std::string name);
	~Weapon(void);
	void		setType(std::string type);
	const std::string& getType() const;
};

#endif
