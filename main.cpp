#include <iostream>
#include <vector>
#include <thread>
using namespace std;

struct Statement
{
    int statementAmount;
    std::string statementType;
};

class accountHolder
{
private:
    int accountNumber, balance;
    string userName;
    vector<Statement> accountHistory;

public:
    accountHolder()
    {
        accountNumber = 0000;
        balance = 00;
        userName = "John Doe";
        
    }
    void showBalance()
    {
        cout << "Balance:" << balance << endl;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << amount << " Euros has been deposited to your account." << endl;
        accountHistory.push_back({amount, "Deposited"});
    }
    void withdraw(int amount)
    {
        int withdrawlAmount = balance - amount;
        if (withdrawlAmount > 0)
        {
            balance -= amount;
            cout << amount << " Euros has been withdrawn from your account." << endl;
            accountHistory.push_back({amount, "Withdrawl"});
        }
        else{
            cout << "You are low on balance\n";
        }
    }
    void setDetails(string name, int feedBalance)
    {
        userName = name;
        balance = feedBalance;
    }
    void bankStatement()
    {
        cout << "Amount    |    Amount \n ----------------------\n";
        for (const auto &item : accountHistory)
        {
            std::cout << item.statementAmount << "    |    " << item.statementType << std::endl;
        }
    }
};

int main()
{
    accountHolder Akhil;
    Akhil.setDetails("Simha", 2400);
    int userInput, depositAmount, withdrawAmount;
    cout << "-------------- Welcome to the BAM ! ----------- " << endl;
    while (true)
    {
        cout << "\nWhat activity would you like to perform: \n------------------------------------ \n 1. Check Balance \n 2. Deposit Money \n 3. Withdraw Money \n 4. Bank Statement \n \nInput: ";
        cin >> userInput;
        cout << "- - - - - - - - - - - - - - - - - - - \n";
        switch (userInput)
        {
        case 1:
            Akhil.showBalance();
            break;
        case 2:
            cout << "How much would you like to deposit: ";
            cin >> depositAmount;
            Akhil.deposit(depositAmount);
            break;
        case 3:
            cout << "How much would you like to deposit: ";
            cin >> withdrawAmount;
            Akhil.withdraw(withdrawAmount);
            break;
        case 4:
            Akhil.bankStatement();
            break;
        default:
            cout << "No/Wrong Input!!!";
            break;
        }
        cout << "- - - - - - - - - - - - - - - - - - - \n";
        std::this_thread::sleep_for(1000ms);
    }
}