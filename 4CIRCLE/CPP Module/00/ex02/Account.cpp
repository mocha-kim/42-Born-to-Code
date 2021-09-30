/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:06:34 by sunhkim           #+#    #+#             */
/*   Updated: 2021/09/30 22:34:29 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::getNbAccounts(void) { return ( Account::_nbAccounts ); }

int	Account::getTotalAmount(void) { return ( Account::_totalAmount ); }

int	Account::getNbDeposits(void) { return ( Account::_totalNbDeposits ); }

int	Account::getNbWithdrawals(void) { return ( Account::_totalNbWithdrawals ); }

void	Account::displayAccountsInfos(void)
{

}

Account::Account( int initial_deposit )
{

}

Account::~Account(void)
{

}

void	Account::makeDeposit(int deposit)
{

}

bool	Account::makeWithdrawal(int withdrawal)
{

}

int		Account::checkAmount(void) const { return (this->_amount > 0); }

void	Account::displayStatus(void) const
{
	
}