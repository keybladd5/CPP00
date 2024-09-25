/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:06:48 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/24 20:06:50 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

static int	_nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    time_t      t_ptr;
    struct tm   *t;

    std::time(&t_ptr);
    t = localtime(&t_ptr);
    std::cout << "[";
    std::cout << t->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << t->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << t->tm_sec;
    std::cout <<"] ";
}

int	Account::getNbAccounts(){return (_nbAccounts);};

int	Account::getTotalAmount(){return (_totalAmount);};

int	Account::getNbDeposits(){return (_totalNbDeposits);};

int	Account::getNbWithdrawals(){return (_totalNbWithdrawals);};

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
};
Account::Account()
{
	_nbAccounts++;
};
Account::Account(int initial_deposit)
{

};
Account::~Account()
{
	
};
void	Account::makeDeposit(int deposit)
{

};
bool	Account::makeWithdrawal(int withdrawal)
{

};
int		Account::checkAmount() const
{

};
void	Account::displayStatus( void ) const
{

};

