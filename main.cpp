#include <iostream>
#include <vector>
#include <thread>
using namespace std;

class accountHolder
{
private:
    int accountNumber, balance;
    string userName;

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
    }
    void withdraw(int amount)
    {
        balance -= amount;
        cout << amount << " Euros has been withdrawn from your account." << endl;
    }
    void setDetails(string name, int feedBalance)
    {
        userName = name;
        balance = feedBalance;
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
        cout << "\nWhat activity would you like to perform: \n------------------------------------ \n 1. Check Balance \n 2. Deposit Money \n 3. Withdraw Money \n \nInput: ";
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
        default:
            cout << "Wrong Input!!!";
            break;
        }
        cout << "- - - - - - - - - - - - - - - - - - - \n";
        std::this_thread::sleep_for(2000ms);
    }
}