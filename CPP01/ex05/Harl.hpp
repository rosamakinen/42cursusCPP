/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:37:09 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 08:49:49 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class	Harl
{
	private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);


	public:

	Harl();
	~Harl(void);
	void	complain(std::string level);

};



#endif
