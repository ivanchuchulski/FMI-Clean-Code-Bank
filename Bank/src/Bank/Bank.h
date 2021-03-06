#pragma once

#ifndef BANK_H
#define BANK_H

#include <vector>

#include "Account/Account.h"
#include "Accounts/CurrentAccount/CurrentAccount.h"	
#include "Accounts/SavingsAccount/SavingsAccount.h"
#include "Accounts/PriviligeAccount/PrivilegeAccount.h"
#include "Customer/Customer.h"
#include "CustomerList/CustomerList.h"
#include "AccountList/AccountList.h"

class Bank 
{
public:
	Bank();
	Bank(const Bank& other);
	Bank(const std::string& bankName, const std::string& bankAddress);

	~Bank();

	Bank& operator=(const Bank& someBank);

	void ChangeBankName(const std::string& name);
	void ChangeBankAddress(const std::string& address);

	const std::string GetName() const;
	const std::string GetAddress() const;

	void AddCustomer(Customer* customer);
	void DeleteCustomer(const std::string& customerName);

	void AddAccount(Account* account);
	void DeleteAccount(const std::string& iban);

	void Transfer(const std::string& fromIBAN, const std::string& toIBAN, double transferAmmount);
	void DepositToAccount(const std::string& accountIBAN, double depositAmmount);
	void WithdrawFromAccount(const std::string& accountIBAN, double withdrawAmmount);

	const CustomerList& GetCustomerList();
	const AccountList& GetAccountList();

	const Customer& GetCustomerByName(const std::string& customerName);

	bool NoRegisteredCustomers() const;
	bool NoOpenedAccounts() const;

private:
	void ClearBank();
	void CopyOtherBank(const Bank& otherBank);

private:
	std::string name;
	std::string address;
	CustomerList customerList;
	AccountList accountList;
};

#endif // !define BANK_H


