#include "BankAccount.h"
#include <sstream>
#include <iomanip>

BankAccount::BankAccount(const std::string& accNum, const std::string& owner)
    : accountNumber(accNum), ownerName(owner), balance(0.0) {
}

std::string BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getOwnerName() const { return ownerName; }
double BankAccount::getBalance() const { return balance; }

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

std::string BankAccount::getInfo() const {
    std::stringstream ss;
    ss << "Konto: " << accountNumber
        << " | Wlasciciel: " << ownerName
        << " | Saldo: " << std::fixed << std::setprecision(2) << balance << " PLN";
    return ss.str();
}