/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:15:09 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/30 21:59:11 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	printHeader(void)
{
	std::cout << "========================================================================================" << std::endl;
	std::cout << "========== ／＞　フ ==       ===  ==========================  ===================  =====" << std::endl;
	std::cout << "========= ( 　_　_l ==  ====  ==  ==========================  ===================  =====" << std::endl;
	std::cout << "======== ／`ミ＿Yノ ==  ====  ==  ==========================  ===================  =====" << std::endl;
	std::cout << "======= /　　　  | ===  ====  ==  ======   ===  = ====   ===  ======   ====   ===  =  ==" << std::endl;
	std::cout << "====== /　ヽ　 　ﾉ ===       ===    ===     ==     ==  =  ==    ===     ==     ==    ===" << std::endl;
	std::cout << "===== │　　|　| | ====  ========  =  ==  =  ==  =  ==     ==  =  ==  =  ==  =  ==   ====" << std::endl;
	std::cout << "= ／￣|　  |　| | ====  ========  =  ==  =  ==  =  ==  =  ==  =  ==  =  ==  =  ==  =  ==" << std::endl;
	std::cout << "= | (￣ヽ＿ヽ_)_) ====  ========  =  ===   ===  =  ===   ===    ====   ====   ===  =  ==" << std::endl;
	std::cout << "= ＼二つ ===============================================================================" << std::endl;
}

int	main(void)
{
	int			state = 0;
	std::string	command;
	Phonebook	phonebook;

	printHeader();
	while (state >= 0)
	{
		if (state == 0)
			std::cout << "Available commands: ADD/SEARCH/EXIT" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			state = phonebook.AddContact();
		else if (command == "SEARCH")
			state = phonebook.SearchPhonebook();
		else
			state = 1;
	}
	return (0);
}