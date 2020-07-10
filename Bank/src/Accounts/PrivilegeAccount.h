#pragma once

#ifndef PRIVILEGE_ACCOUNT_H
#define PRIVILEGE_ACCOUNT_H

#include "Account/Account.h"

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const PrivilegeAccount& other) = default;
	PrivilegeAccount(const std::string& ownerID);
	PrivilegeAccount(const std::string& ownerID, double initialDeposit, double overdraft);

	virtual ~PrivilegeAccount() = default;

	PrivilegeAccount& operator=(const PrivilegeAccount& other);

	const double GetOverdraft() const;

	void IncreaseOverdraft(double overdraftIncrease);
	void DecreaseOverdraft(double overdraftDecrease);

	virtual void Deposit(double depositAmmount) override;
	virtual void Withdraw(double withdrawAmmount) override;
	virtual void DisplayAccount() const override;
	virtual int GetAccountType() const override;
	virtual Account* CloneAccount() const override;

	friend std::ostream& operator<<(std::ostream& outStream, const PrivilegeAccount& somePrivilAcc);

private:
	static const double M_OVERDRAFT_DEFAULT;

private:
	double m_overdraftOverBalance;
};

#endif // !PRIVILEGE_ACCOUNT_H
