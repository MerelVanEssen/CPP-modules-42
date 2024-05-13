/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <mvan-ess@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:32:33 by mvan-ess          #+#    #+#             */
/*   Updated: 2024/05/07 07:31:07 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};

Harl::~Harl() {};

void	Harl::debug(void)
{
	std::cout 	<< GREEN "[ DEBUG ]" RESET << std::endl
			 	<< "I love having extra bacon for my " 
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout 	<< YELLOW "[ INFO ]" RESET << std::endl
				<< "I cannot believe adding extra bacon costs more money. " 
				<< "You didn’t put enough bacon in my burger! "
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout 	<< PURPLE "[ WARNING ]" RESET << std::endl
				<< "I think I deserve to have some extra bacon for free. " 
				<< "I've been coming for years whereas you started working here since last month."
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout 	<< RED "[ ERROR ]" RESET << std::endl
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void	Harl::complain(std::string level)
{
	functions	t_func[] =  {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	names[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (level.compare(names[i]) == 0)
		{
			(this->*t_func[i])();
			return ;
		}
		i++;
	}
	std::cout << "Nothing to complain today." << std::endl;
}
