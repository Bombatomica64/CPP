/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:41:26 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/03 10:50:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
	
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "Accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}