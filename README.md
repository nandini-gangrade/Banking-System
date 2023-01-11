## Banking-System
<p>
<ul>
  <li>'Account' class</li>
    <ul>
      <li>Represents a single bank account and has private member variables such as accountNumber, firstName, lastName and balance to store the account number, first and last name of the account holder, and the current account balance respectively.</li>
      <li>It also has a static variable NextAccountNumber that is used to assign unique account numbers to new accounts. This variable is incremented every time a new account is created to ensure that each account has a unique number.</li>
      <li>The class has several member functions such as Deposit(float amount), Withdraw(float amount), getAccNo(), getFirstName(),getLastName() and getBalance() which are used to perform the basic operations on the account such as deposit, withdraw, getting account number, first name, last name, and balance respectively. These functions provide a way to access and manipulate the private member variables of the class in a controlled way.</li>
      <li>The class also has a constructor which assigns the account number, first name, last name, and balance to the account instance. The constructor also increments the static variable NextAccountNumber for each new account.</li>
      <li>Deposit(float amount) - This function takes an amount as an argument, and adds it to the current account balance. It is used to increase the account balance by the deposited amount.</li>
      <li>Withdraw(float amount) - This function takes an amount as an argument, checks if the account has enough balance to withdraw the requested amount, if not it throws an exception of InsufficientFunds and if it is possible, it subtracts the requested amount from the balance. It is used to decrease the account balance by the withdrawn amount.</li>
      <li>getAccNo() , getFirstName(),getLastName(), and getBalance() are simple getter functions which return the account number, first name, last name, and balance of the account respectively. They are used to retrieve the account information.</li>
      <li>setLastAccountNumber(long accountNumber) and getLastAccountNumber() are static functions, these functions allow to set or get the value of the last account number created.</li>
      <li>friend ofstream & operator<<(ofstream &ofs,Account &acc) and friend ifstream & operator>>(ifstream &ifs,Account &acc) and friend ostream & operator<<(ostream &os,Account &acc) are friend functions, which are non-member functions that have access to the private and protected members of the class. These functions allow you to handle file input/output and standard output for Account objects.</li>
    </ul>
  <li>'Bank' class:</li>
    <ul>
      <li>Represents the bank itself and has a private member variable accounts which is a map of account numbers to Account objects. This allows the bank to keep track of all the accounts it manages.</li>
      <li>The class has several member functions, such as OpenAccount(string fname,string lname,float balance), BalanceEnquiry(long accountNumber), Deposit(long accountNumber,float amount), Withdraw(long accountNumber,float amount), CloseAccount(long accountNumber), and ShowAllAccounts() which are used to perform the basic bank operations such as creating new accounts, checking account balances, depositing and withdrawing money, closing accounts, and displaying all accounts.</li>
      <li>OpenAccount(string fname,string lname,float balance) - This function takes the first name, last name, and initial balance of the account as arguments and creates a new Account object with these values. It adds the new account to the bank's map of accounts and returns the new account.</li>
      <li>BalanceEnquiry(long accountNumber) - This function takes an account number as an argument and returns the Account object corresponding to that number from the map of accounts. If the account number does not exist in the map, the function throws an exception.</li>
      <li>Deposit(long accountNumber,float amount) - This function takes an account number and an amount as arguments, finds the corresponding account in the map of accounts, and calls the Deposit function on that account to add the amount to the balance.</li>
      <li>Withdraw(long accountNumber,float amount) - This function takes an account number and an amount as arguments, finds the corresponding account in the map of accounts, and calls the Withdraw function on that account to subtract the amount from the balance.</li>
      <li>CloseAccount(long accountNumber) - This function takes an account number as an argument and removes the corresponding account from the map of accounts.</li>
      <li>ShowAllAccounts() - This function iterates through the map of accounts and displays information about all accounts in the bank.</li>
      <li>~Bank()- a destructor which is called when the Bank object is destroyed. It is used to perform any necessary cleanup operations before theBank` object is destroyed, such as saving the current state of the bank's accounts to a file.</li>
    </ul>
  <li>'InsufficientFunds' class:</li>
     <ul>
       <li>It is an exception class, which can be thrown when a user attempts to withdraw more money than they currently have in their account, this class has no member functions or variables.</li>
     </ul>
  <li>The main function provides a menu-driven interface that allows the user to interact with the bank and perform the different operations. The user is presented with a list of options and can select one of the options using an integer input. Depending on the option selected, the corresponding function from the Bank class is called to perform the operation. Additionally, it also has a catch block to catch exception of InsufficientFunds</li>
</ul>
<p>Overall, this program allows the user to understand and practice the basic principles of object-oriented programming, encapsulation, inheritance, polymorphism and how to use the map data structure in C++. Exception handling is also used to handle the error condition of insufficient balance.</p>
</p>
