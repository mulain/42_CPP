/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:45:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/05 21:33:53 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << this->_name << " sprang to unlife!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " dieded." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

 /*
Then, implement the two following functions:
• Zombie* newZombie( std::string name );
It creates a zombie, name it, and return it so you can use it outside of the function
scope.

• void randomChump( std::string name );
It creates a zombie, name it, and the zombie announces itself.
Now, what is the actual point of the exercise? You have to determine in what case
it’s better to allocate the zombies on the stack or heap.

*/