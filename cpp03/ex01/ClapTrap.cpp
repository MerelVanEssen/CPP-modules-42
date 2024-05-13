/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:07:33 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/09 07:33:27 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << GRE "Default ClapTrap created" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GRE << name << " is created" RES << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << GRE "ClapTrap Copy constructor is called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED "ClapTrap Destructor is called for: " << this->_name << std::endl; 
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	this->_name = obj._name;
	this->_energyPoints = obj._energyPoints;
	this->_hitPoints = obj._hitPoints;
	this->_damage = obj._damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << RED << this->_name << " has no energie to attack." << std::endl;
		return ;	
	}
	this->_energyPoints--;
	std::cout	<< YEL "ClapTrap " << this->_name << " attacks "
				<< target << " causing " << this->_damage 
				<< " points of damage." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;
	std::cout 	<< RED << this->_name << " recieved " << amount
				<< " of damage ";
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << "and died!" RES << std::endl;
		this->_hitPoints = 0;
	}
	else
	{
		std::cout	<< "and has " << this->_hitPoints 
					<< " hitpoints left" RES << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return ;
	if (this->_energyPoints == 0)
	{
		std::cout << RED << this->_name << " has no energie to heal." << std::endl;
		return ;	
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout	<< GRE << this->_name << " is repaired with " << amount
				<< " and has now " << this->_hitPoints << std::endl;
}
