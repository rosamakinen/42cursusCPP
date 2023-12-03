#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain &another);
		Brain &operator=(const Brain &another);

		std::string	getIdea(int index);
		void	setIdea(int index, std::string idea);

};

#endif