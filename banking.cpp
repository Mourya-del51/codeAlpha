#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Transaction class
class Transaction {
public:
    string type;
    double amount;
    time_t date;
    double balanceAfter;

    Transaction(string type, double amount, double balanceAfter) {
        this->type = type;
        this->amount = amount;
        this->date = time(0);
        this->balanceAfter = balanceAfter;
    }

    void display() {
        cout << ctime(&date)
             << " | " << type
             << " | Amount: ₹" << amount
             << " | Balance After: ₹" << balanceAfter << endl;
    }
};

// Account class
class Account {
public:
    int accountNumber;
    string accountType;
    double balance;
    vector<Transaction> transactions;

    Account(int accNum, string type) {
        accountNumber = accNum;
        accountType = type;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.emplace_back("Deposit", amount, balance);
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "❌ Insufficient Balance.\n";
            return false;
        }
        balance -= amount;
        transactions.emplace_back("Withdrawal", amount, balance);
        return true;
    }

    bool transfer(Account &toAccount, double amount) {
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            transactions.emplace_back("Transfer Out", amount, balance);
            toAccount.transactions.emplace_back("Transfer In", amount, toAccount.balance);
            return true;
        }
        return false;
    }

    void showTransactions() {
        cout << "📜 Transaction History for A/C " << accountNumber << ":\n";
        for (auto &t : transactions) {
            t.display();
        }
    }

    void showAccountInfo() {
        cout << "📌 Account Number: " << accountNumber
             << "\n💼 Type: " << accountType
             << "\n💰 Balance: ₹" << balance << endl;
        showTransactions();
    }
};

// Customer class
class Customer {
public:
    string name;
    int customerId;
    vector<Account> accounts;

    Customer(int id, string name) {
        this->name = name;
        this->customerId = id;
    }

    void addAccount(Account account) {
        accounts.push_back(account);
    }

    Account* getAccountByNumber(int accNum) {
        for (auto &acc : accounts) {
            if (acc.accountNumber == accNum) {
                return &acc;
            }
        }
        return nullptr;
    }

    void showCustomerInfo() {
        cout << "\n👤 Customer ID: " << customerId
             << "\n🧑 Name: " << name << "\n";
        for (auto &acc : accounts) {
            acc.showAccountInfo();
        }
    }
};

// Simple demo main
int main() {
    // Create customers
    Customer c1(1, "Amit Sharma");
    Customer c2(2, "Neha Verma");

    // Create accounts
    Account acc1(1001, "Savings");
    Account acc2(1002, "Current");

    // Add accounts to customers
    c1.addAccount(acc1);
    c2.addAccount(acc2);

    // Perform operations
    Account *a1 = c1.getAccountByNumber(1001);
    Account *a2 = c2.getAccountByNumber(1002);

    a1->deposit(5000);
    a1->withdraw(1500);
    a1->transfer(*a2, 1000);

    // Display info
    c1.showCustomerInfo();
    c2.showCustomerInfo();

    return 0;
}
