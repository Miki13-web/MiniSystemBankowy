#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    BankAccount(const std::string& accNum, const std::string& owner);

    std::string getAccountNumber() const;
    std::string getOwnerName() const;
    double getBalance() const;

    // Metody zwracaj¹ informacje o powodzeniu operacji
    void deposit(double amount);
    bool withdraw(double amount);
    std::string getInfo() const; // Zamiast printowania string
};

#endif
