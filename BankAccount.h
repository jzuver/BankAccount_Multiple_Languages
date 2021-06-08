

#ifndef M3OEP_MPL_JZUVER_BANKACCOUNT_H
#define M3OEP_MPL_JZUVER_BANKACCOUNT_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


class BankAccount {
private:
    string userName;
    string userPassword;
    float checkingAccountBalance;
    float savingsAccountBalance;
public:

    /**
    * Default constructor
    * Requires: nothing
    * Modifies: userName, userPassword, and accountBalance fields
    * Effects: calls default constructor and sets fields to default values
    */
    BankAccount();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns userName field
    */
    string getUserName() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns userPassword field
    */
    string getUserPassword() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns userPassword field
    */
    float getCheckingAccountBalance() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns userPassword field
    */
    float getSavingsAccountBalance() const;

    /**
    * Requires: string value as argument
    * Modifies: userName field
    * Effects: sets userName field
    */
    void setUserName(string name);

    /**
    * Requires: string value as argument
    * Modifies: userPassword field
    * Effects: sets userPassword field
    */
    void setUserPassword(string password);

    /**
    * Requires: float value as argument
    * Modifies: checkingAccountBalance field
    * Effects: sets checkingAccountBalance field
    */
    void setCheckingAccountBalance(float checkingBalance);

    /**
    * Requires: float value as argument
    * Modifies: savingsAccountBalance field
    * Effects: sets savingsAccountBalance  field
    */
    void setSavingsAccountBalance(float savingsBalance);

    /**
    * Requires: float value as argument
    * Modifies: savingsAccountBalance or checkingAccountBalance fields
    * Effects: deposits the passed in amount to the specified account
    */
    void deposit(float toBeDeposited, string account);

    /**
    * Requires: float value as argument
    * Modifies: savingsAccountBalance or checkingAccountBalance fields
    * Effects: withdraws the passed in amount to the specified account
    */
    void withdraw(float toBeWithdrawn, string account);


    /**
    * Requires: nothing
    * Modifies: userName and userPassword fields
    * Effects: prompts the user to create a username and password, and then to log in
    */
    void createAccount();

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: prompts to either deposit, withdraw, or check balance
    */
    void bankMenu();
};
#endif //M3OEP_MPL_JZUVER_BANKACCOUNT_H