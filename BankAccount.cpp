#include "BankAccount.h"

/*************************** BankAccount class definitions *********************/


BankAccount::BankAccount() {
    userName = "default";
    userPassword = "default";
    checkingAccountBalance = 0;
    savingsAccountBalance = 0;
}


/*************** Getters *********************/
string BankAccount::getUserName() const {
    return userName;
}

string BankAccount::getUserPassword() const {
    return userPassword;
}

float BankAccount::getCheckingAccountBalance() const {
    return checkingAccountBalance;
}

float  BankAccount::getSavingsAccountBalance() const {
    return savingsAccountBalance;
}

/*************** Setters *********************/

void BankAccount::setUserName(string name) {
    userName = name;
}

void BankAccount::setUserPassword(string password) {
    userPassword = password;
}

void BankAccount::setCheckingAccountBalance(float checkingBalance) {
    checkingAccountBalance = checkingBalance;
}

void BankAccount::setSavingsAccountBalance(float savingsBalance) {
    savingsAccountBalance = savingsBalance;
}

/***************** Other Methods *********************/

 void BankAccount::deposit(float toBeDeposited, string account) {
    if(account == "checking"){
        checkingAccountBalance = checkingAccountBalance + toBeDeposited;
    }
    else if(account == "savings"){
        savingsAccountBalance = savingsAccountBalance + toBeDeposited;
    }
    else{
        cout << "Invalid account" << endl;
    }
}

void BankAccount::withdraw(float toBeWithdrawn, string account) {

    if(account == "checking"){

        // check if account is empty, if not withdraw
        if(checkingAccountBalance > 0){
            checkingAccountBalance = checkingAccountBalance - toBeWithdrawn;
        }
        // display account empty message to user
        else{
            cout << "Your account is empty, no money can be withdrawn." << endl;
        }
    }
    else if(account == "savings"){

        // check if account is empty, if not withdraw
        if(savingsAccountBalance > 0){
            savingsAccountBalance = savingsAccountBalance - toBeWithdrawn;
        }
        // display account empty message to user
        else{
            cout << "Your account is empty, no money can be withdrawn." << endl;
        }
    }
    else{
        cout << "Invalid Account" << endl;
    }
}

void BankAccount::createAccount() {
     bool isValid = false;
     string name;
     string password;
     string userNameAttempt;
     string passwordAttempt;

     // prompt user to create account
     // username
     cout << "Please create an account to continue." << endl;
     cout << "Please enter your desired username: ";
     cin >> name;
     setUserName(name);

     // password
     cout << "\nPlease enter your desired password: ";
     cin >> password;
     setUserPassword(password);

     // prompt user to "login"
     cout << "\nThank you for creating an account with Zuver Banking. Please login to continue." << endl;

     while(!isValid){

         // get login attempt
         cout << "Username: ";
         cin >> userNameAttempt;
         cout << "\nPassword: ";
         cin >> passwordAttempt;

         // if login successful, lower flag
         if(password == passwordAttempt && name == userNameAttempt){
             isValid = true;
         }
         else{
             cout << "Invalid, either the username or password is incorrect. Please try again." << endl;
         }
     }

 }

 void BankAccount::bankMenu() {
     bool keepRunning = true;
     int userChoice;

     while(keepRunning){

         // display options to user
         cout << "\nPlease enter the number associated with your choice.";
         cout << "\n1. Check Balance.";
         cout << "\n2. Deposit.";
         cout << "\n3. Withdraw.";
         cout << "\n4. Exit. (This will display a Bar graph and Pie Chart)";
         cout << "\nYour choice: ";


         //validate user input
         while((!(cin >> userChoice)) || userChoice < 1 || userChoice > 4){
             cout << "\nInvalid choice. Please enter either 1, 2, 3, or 4.\n";
             cin.clear();
             string junk;
             getline(cin, junk);
         }

         // display balance
         if(userChoice == 1){
             cout << "\nChecking Account Balance : " << checkingAccountBalance << endl;
             cout << "Savings Account Balance: " << savingsAccountBalance << endl;
         }

         // deposit into desired account
         else if (userChoice == 2){
             float depositThisMuch = 0;
             int accountChoice;
             string thisAccount;

             // prompt user which account, validate choice
             cout << "\nWhich account would you like to deposit into?";
             cout << "\n1. Checking.";
             cout << "\n2. Savings.";
             cout << "\nYour choice: ";
             while (!(cin >> accountChoice) || accountChoice < 1 || accountChoice > 2){
                 cout << "\nInvalid choice. Please enter either 1 or 2.\n";
                 cin.clear();
                 string junk;
                 getline(cin, junk);
             }

             // change thisAccount value to chose account
             if (accountChoice == 1){
                 thisAccount = "checking";
             }
             else{
                 thisAccount = "savings";
             }

             // prompt user to enter amount to be deposited, input validated
             cout << "Please enter the amount you would like to deposit: ";
             while (!(cin >> depositThisMuch)){
                 cout << "\nInvalid choice. Please enter a numerical value.\n";
                 cin.clear();
                 string junk;
                 getline(cin, junk);
             }

             // deposit the money into the account
             deposit(depositThisMuch, thisAccount);


         }

         // withdraw desired amount
         else if (userChoice == 3){
             float withdrawThisMuch = 0;
             int accountChoice;
             string thisAccount;

             // prompt user which account, validate choice
             cout << "\nWhich account would you like to withdraw from?";
             cout << "\n1. Checking.";
             cout << "\n2. Savings.";
             cout << "\nYour choice: ";
             while (!(cin >> accountChoice) || accountChoice < 1 || accountChoice > 2){
                 cout << "\nInvalid choice. Please enter either 1 or 2.\n";
                 cin.clear();
                 string junk;
                 getline(cin, junk);
             }

             // change thisAccount value to chose account
             if (accountChoice == 1){
                 thisAccount = "checking";
             }
             else{
                 thisAccount = "savings";
             }

             // prompt user to enter amount to be withdrawn, input validated
             cout << "Please enter the amount you would like to withdraw: ";
             while (!(cin >> withdrawThisMuch)){
                 cout << "\nInvalid choice. Please enter a numerical value.\n";
                 cin.clear();
                 string junk;
                 getline(cin, junk);
             }

             // deposit the money into the account
             withdraw(withdrawThisMuch, thisAccount);

         }
         // exit the program, print python graphs
         else{
             keepRunning = false;
         }


     }

 }





