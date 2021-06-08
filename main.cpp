#include <iostream>
#include <string>
#include "BankAccount.h"

int main() {

    BankAccount b;
    b.createAccount();
    b.bankMenu();

    // graph checking and savings account to user
    float checking = b.getCheckingAccountBalance();
    float savings  = b.getSavingsAccountBalance();
    const string python = "python";
    string command = python + " ../display.py " + std::to_string(checking) + " " + std::to_string(savings);

    // run python file with command line arguments
    system(command.c_str());



    return 0;
}
