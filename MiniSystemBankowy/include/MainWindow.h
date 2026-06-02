#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <vector>
#include "BankAccount.h"

// forward declarations
class QLineEdit;
class QTextEdit;
class QPushButton;

class MainWindow : public QWidget {
    Q_OBJECT

private:
    std::vector<BankAccount> accounts;

    //elementy interface
    QLineEdit* accNumInput;
    QLineEdit* ownerInput;
    QLineEdit* amountInput;
    QTextEdit* logOutput;

    // metody
    BankAccount* findAccount(const std::string& accNum);
    void logMessage(const QString& msg);

private slots:
    // obsluga klikniec
    void handleCreateAccount();
    void handleDeposit();
    void handleWithdraw();
    void handleDisplay();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() = default;
};

#endif 