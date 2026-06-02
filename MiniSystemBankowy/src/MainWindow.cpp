#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Mini System Bankowy (Qt)");
    resize(500, 400);

    // init widgetow
    accNumInput = new QLineEdit(this);
    ownerInput = new QLineEdit(this);
    amountInput = new QLineEdit(this);
    logOutput = new QTextEdit(this);
    logOutput->setReadOnly(true);

    QPushButton* btnCreate = new QPushButton("Utworz konto", this);
    QPushButton* btnDeposit = new QPushButton("Wplac", this);
    QPushButton* btnWithdraw = new QPushButton("Wyplac", this);
    QPushButton* btnInfo = new QPushButton("Informacje", this);

    //layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* inputLayout = new QHBoxLayout();
    QVBoxLayout* labelsLayout = new QVBoxLayout();
    QVBoxLayout* fieldsLayout = new QVBoxLayout();

    labelsLayout->addWidget(new QLabel("Numer konta:"));
    labelsLayout->addWidget(new QLabel("Wlasciciel:"));
    labelsLayout->addWidget(new QLabel("Kwota:"));

    fieldsLayout->addWidget(accNumInput);
    fieldsLayout->addWidget(ownerInput);
    fieldsLayout->addWidget(amountInput);

    inputLayout->addLayout(labelsLayout);
    inputLayout->addLayout(fieldsLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(btnCreate);
    buttonsLayout->addWidget(btnDeposit);
    buttonsLayout->addWidget(btnWithdraw);
    buttonsLayout->addWidget(btnInfo);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addWidget(new QLabel("Logi operacji:"));
    mainLayout->addWidget(logOutput);

    //ubsluga klikniec
    connect(btnCreate, &QPushButton::clicked, this, &MainWindow::handleCreateAccount);
    connect(btnDeposit, &QPushButton::clicked, this, &MainWindow::handleDeposit);
    connect(btnWithdraw, &QPushButton::clicked, this, &MainWindow::handleWithdraw);
    connect(btnInfo, &QPushButton::clicked, this, &MainWindow::handleDisplay);

    logMessage("System gotowy do pracy.");
}

BankAccount* MainWindow::findAccount(const std::string& accNum) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accNum) {
            return &account;
        }
    }
    return nullptr;
}

void MainWindow::logMessage(const QString& msg) {
    logOutput->append(msg);
}

void MainWindow::handleCreateAccount() {
    std::string accNum = accNumInput->text().toStdString();
    std::string owner = ownerInput->text().toStdString();

    if (accNum.empty() || owner.empty()) {
        QMessageBox::warning(this, "Blad", "Numer konta i dane wlasciciela nie moga byc puste!");
        return;
    }

    if (findAccount(accNum) != nullptr) {
        QMessageBox::warning(this, "Blad", "Konto o tym numerze juz istnieje!");
        return;
    }

    accounts.emplace_back(accNum, owner);
    logMessage(QString("Utworzono nowe konto: %1").arg(QString::fromStdString(accNum)));

    accNumInput->clear();
    ownerInput->clear();
}

void MainWindow::handleDeposit() {
    std::string accNum = accNumInput->text().toStdString();
    bool ok;
    double amount = amountInput->text().toDouble(&ok);

    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Blad", "Podaj poprawna kwote wieksza od 0!");
        return;
    }

    BankAccount* acc = findAccount(accNum);
    if (acc) {
        acc->deposit(amount);
        logMessage(QString("Wplacono %1 PLN na konto %2.").arg(amount).arg(QString::fromStdString(accNum)));
        amountInput->clear();
    }
    else {
        QMessageBox::warning(this, "Blad", "Nie znaleziono konta!");
    }
}

void MainWindow::handleWithdraw() {
    std::string accNum = accNumInput->text().toStdString();
    bool ok;
    double amount = amountInput->text().toDouble(&ok);

    if (!ok || amount <= 0) {
        QMessageBox::warning(this, "Blad", "Podaj poprawna kwote wieksza od 0!");
        return;
    }

    BankAccount* acc = findAccount(accNum);
    if (acc) {
        if (acc->withdraw(amount)) {
            logMessage(QString("Wyplacono %1 PLN z konta %2.").arg(amount).arg(QString::fromStdString(accNum)));
            amountInput->clear();
        }
        else {
            // blokada wyplaty ponad saldo
            QMessageBox::critical(this, "Odmowa", "Brak wystarczajacych srodkow na koncie!");
        }
    }
    else {
        QMessageBox::warning(this, "Blad", "Nie znaleziono konta!");
    }
}

void MainWindow::handleDisplay() {
    std::string accNum = accNumInput->text().toStdString();
    BankAccount* acc = findAccount(accNum);

    if (acc) {
        logMessage(QString::fromStdString(acc->getInfo()));
    }
    else {
        QMessageBox::warning(this, "Blad", "Nie znaleziono konta!");
    }
}