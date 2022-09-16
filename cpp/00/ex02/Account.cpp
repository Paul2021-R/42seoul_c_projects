/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:44:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/14 23:45:38 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account() :
	_accountIndex (0),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{}

Account::Account(const int* deposit_arr, int* ptr) {
	int* CopyArr = (int *)deposit_arr;
	int	size = (ptr - CopyArr) / sizeof(int);
	Account* t = new Account[size];
	for (int i = 0; i < size; i++) {
		t[i]._accountIndex = i;
		t[i]._amount = deposit_arr[i];
		t[i]._nbDeposits = 0;
		t[i]._nbWithdrawals = 0;
		std::cout << "날짜 어떻게 함?" << " index:" << i << ";ammount:" << t[i]._amount << "; created" << std::endl;
	}

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
