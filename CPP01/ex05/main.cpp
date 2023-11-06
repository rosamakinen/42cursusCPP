/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 07:57:11 by rmakinen          #+#    #+#             */
/*   Updated: 2023/11/06 09:24:14 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	haren;
	if (argc == 2)
	{
		std::string	level = argv[1];
		haren.complain(level);
	}
	else
		std::cout << "wrong number of arguments, try running the executable with one argument" << std::endl;
}
