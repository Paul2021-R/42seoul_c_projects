/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:44:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/16 15:36:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
	time_t CurTime = time(NULL);
	struct tm *pLocal = localtime(&CurTime);
	std::cout << "[" << pLocal->tm_year << pLocal->tm_mon << pLocal->tm_mday << "_" << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] "
}

Account::Account() {

}

Account::~Account(void) {

}

void	Account::makeDeposit(int initial_deposit) {

}

bool	Account::makeWithdrawal(int withdrawal) {

	return (true);
}

int		Account::checkAmount() const {

	return (0);
}

void	Account::displayStatus() const {

}

int		Account::getNbAccounts(void) {
	return (0);
}

int		Account::getTotalAmount(void) {
	return (0);
}

int		Account::getNbDeposits(void) {
	return (0);
}

int		Account::getNbWithdrawals(void) {
	return (0);
}

void	Account::displayAccountsInfos(void) {
	return ;
}
