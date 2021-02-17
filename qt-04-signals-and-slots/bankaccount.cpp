#include "bankaccount.h"

BankAccount::BankAccount(Bank *parentBank) : QObject(parentBank)
{
    m_balance = 0;

    connect(this, SIGNAL(balanceChanged(long)),
    parentBank, SLOT(updateTotalBalance()));
}

long BankAccount::balance() const
{
    return m_balance;
}

void BankAccount::setBalance(long newBalance)
{
    m_balance = newBalance;
    emit balanceChanged(m_balance);
}

void BankAccount::deposit(long amount)
{
    setBalance(m_balance + amount);
}

void BankAccount::withdraw(long amount)
{
    setBalance(m_balance - amount);
}
