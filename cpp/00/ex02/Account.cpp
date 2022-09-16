/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:44:19 by haryu             #+#    #+#             */
/*   Updated: 2022/09/16 20:28:08 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
	time_t CurTime = time(NULL);
	struct tm *pLocal = localtime(&CurTime);
	std::cout << "[" << pLocal->tm_year + 1900 << pLocal->tm_mon << pLocal->tm_mday << "_" << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] ";
}

Account::Account() :
	_accountIndex (0),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0)
{}

Account::Account(int initial_deposit) :
	_accountIndex (0),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0) {
		static int i = 0;
		_nbAccounts++;
		_accountIndex = i;
		_displayTimestamp();
		std::cout << "index:" << i;
		std::cout << ";amount:" << checkAmount();
		std::cout << ";created" << std::endl;
		_totalAmount += _amount;
		i++;
	}

Account::Account(const int* deposit_arr, int* ptr) {
	int* CopyArr = (int *)deposit_arr;
	int	size = sizeof(*CopyArr) / sizeof(int);
	(void)ptr;
	Account* t[size];
	for (int i = 0; i < size; i++) {
		t[i]->_accountIndex = i;
		t[i]->_amount = CopyArr[i];
		t[i]->_nbDeposits = 0;
		t[i]->_nbWithdrawals = 0;
		_displayTimestamp();
		std::cout << "index:" << i ;
		std::cout << ";ammount:" << t[i]->_amount ;
		std::cout << ";created" << std::endl;
		_totalAmount += CopyArr[i];
	}
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit(int initial_deposit) {
	if (initial_deposit != 0){
		_nbDeposits++;
		_totalNbDeposits++;
		int AfterAmount = _amount + initial_deposit;
		_totalAmount -= _amount;
		_totalAmount += AfterAmount;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";deposit:" << initial_deposit;
		std::cout << ";amount:" << AfterAmount;
		std::cout << ";nb_deposit:" << _nbDeposits << std::endl;
		_amount = AfterAmount;
	}	
	else {
		_totalNbDeposits += _nbDeposits;
		int AfterAmount = 0;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";deposit:" << initial_deposit;
		std::cout << ";amount:" << AfterAmount;
		std::cout << ";nb_deposit:" << _nbDeposits << std::endl;
		_amount = AfterAmount;
	}
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal) {
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		int AfterAmount = _amount - withdrawal;
		_totalAmount -= _amount;
		_totalAmount += AfterAmount;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << AfterAmount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount = AfterAmount;
		return (true);
	}
	else {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << checkAmount();
		std::cout << ";withdrawal:" << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount() const {
	return (_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposit:" << _nbDeposits;
	std::cout << ";withdrawals:"<< _nbWithdrawals << std::endl;
}

int		Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int		Account::getTotalAmount(void) {
	return (_totalAmount);
}

int		Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "account:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}
