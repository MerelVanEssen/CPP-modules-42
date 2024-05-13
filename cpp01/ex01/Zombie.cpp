/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:18:56 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/07 07:20:01 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << GREEN "A zombie is created" RESET << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << RED << this->_name << " is destroyed" RESET << std::endl;
}

std::string	Zombie::getName(void) const
{
	return (this->_name);
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << YELLOW << this->_name << " BraiiiiiiinnnzzzZ..." RESET << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
	Zombie	*zom;

	zom = new Zombie();
	zom->setName(name);
	return (zom);
}

void	Zombie::randomChump(std::string name)
{
	setName(name);
	announce();
}