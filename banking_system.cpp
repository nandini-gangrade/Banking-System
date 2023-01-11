#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
using namespace std;

#define MIN_BALANCE 500

// Exception class for insufficient funds
class InsufficientFunds{};
class Account
{
private:
 long accountNumber; // Account number
 string firstName;   // First name of account holder
 string lastName;    // Last name of account holder
 float balance;      // Current account balance
 static long NextAccountNumber; // Next account number to be assigned
public:
 //default constructor 
 Account(){}
 //parametrized constructor
 Account(string fname,string lname,float balance);
 //getter functions
 long getAccNo(){return accountNumber;}
 string getFirstName(){return firstName;}
 string getLastName(){return lastName;}
 float getBalance(){return balance;}
 
 // Deposit money into the account
 void Deposit(float amount);
 // Withdraw money from the account
 void Withdraw(float amount);
 // Set the last account number used
 static void setLastAccountNumber(long accountNumber);
 // Get the last account number used
 static long getLastAccountNumber();
 
 // Friend functions to handle file input/output
 friend ofstream & operator<<(ofstream &ofs,Account &acc);
 friend ifstream & operator>>(ifstream &ifs,Account &acc);
 // Friend function to handle standard output
 friend ostream & operator<<(ostream &os,Account &acc);
};

long Account::NextAccountNumber=0;

class Bank
{
private:
 // Map of account numbers to Account objects
 map<long,Account> accounts;
public:
 //default constructor
 Bank();
 // Create a new account
 Account OpenAccount(string fname,string lname,float balance);
 // Get the balance of an existing account
 Account BalanceEnquiry(long accountNumber);
 // Deposit money into an existing account
 Account Deposit(long accountNumber,float amount);
 // Withdraw money from an existing account
 Account Withdraw(long accountNumber,float amount);
 // Close an existing account
 void CloseAccount(long accountNumber);
 // Show all existing accounts
 void ShowAllAccounts();
 ~Bank();
};
int main()
{
 // Destructor
 Bank b;
 Account acc;
 
 int choice;
 string fname,lname;
 long accountNumber;
 float balance;
 float amount;
 cout<<"***Banking System***"<<endl;
 do
 {
 cout<<"\n\tSelect one option below ";
 cout<<"\n\t1 Open an Account";
 cout<<"\n\t2 Balance Enquiry";
 cout<<"\n\t3 Deposit";
 cout<<"\n\t4 Withdrawal";
 cout<<"\n\t5 Close an Account";
 cout<<"\n\t6 Show All Accounts";
 cout<<"\n\t7 Quit";
 cout<<"\nEnter your choice: ";
 cin>>choice;
 switch(choice)
 {
 case 1:
 cout<<"Enter First Name: ";
cin>>fname;
cout<<"Enter Last Name: ";
cin>>lname;
cout<<"Enter Initil Balance: ";
cin>>balance;
 acc=b.OpenAccount(fname,lname,balance);
 cout<<endl<<"Congratulation Account is Created"<<endl;
 cout<<acc;
break;
 case 2:
 cout<<"Enter Account Number:";
cin>>accountNumber;
 acc=b.BalanceEnquiry(accountNumber);
 cout<<endl<<"Your Account Details"<<endl;
 cout<<acc;
break;
 case 3:
 cout<<"Enter Account Number:";
cin>>accountNumber;
cout<<"Enter Balance:";
cin>>amount;
 acc=b.Deposit(accountNumber, amount);
 cout<<endl<<"Amount is Deposited"<<endl;
 cout<<acc;
break;
 case 4:
 cout<<"Enter Account Number:";
cin>>accountNumber;
cout<<"Enter Balance:";
cin>>amount;
 acc=b.Withdraw(accountNumber, amount);
 cout<<endl<<"Amount Withdrawn"<<endl;
 cout<<acc;
break;
 case 5:
 cout<<"Enter Account Number:";
cin>>accountNumber;
 b.CloseAccount(accountNumber);
 cout<<endl<<"Account is Closed"<<endl;
 cout<<acc;
 case 6:
 b.ShowAllAccounts();
 break;
 case 7: break;
 default:
 cout<<"\nEnter Correct Choice";
exit(0);
 }
 }while(choice!=7);
 
 return 0;
}
Account::Account(string fname,string lname,float balance)
{
 NextAccountNumber++;
 accountNumber=NextAccountNumber;
 firstName=fname;
 lastName=lname;
 this->balance=balance;
}
void Account::Deposit(float amount)
{
 balance+=amount;
}
void Account::Withdraw(float amount)
{
 if(balance-amount<MIN_BALANCE)
 throw InsufficientFunds();
 balance-=amount;
}
void Account::setLastAccountNumber(long accountNumber)
{
 NextAccountNumber=accountNumber;
}
long Account::getLastAccountNumber()
{
 return NextAccountNumber;
}
ofstream & operator<<(ofstream &ofs,Account &acc)
{
 ofs<<acc.accountNumber<<endl;
 ofs<<acc.firstName<<endl;
 ofs<<acc.lastName<<endl;
 ofs<<acc.balance<<endl;
 return ofs;
}
ifstream & operator>>(ifstream &ifs,Account &acc)
{
 ifs>>acc.accountNumber;
 ifs>>acc.firstName;
 ifs>>acc.lastName;
 ifs>>acc.balance;
 return ifs;
 
}
ostream & operator<<(ostream &os,Account &acc)
{
 os<<"First Name:"<<acc.getFirstName()<<endl;
 os<<"Last Name:"<<acc.getLastName()<<endl;
 os<<"Account Number:"<<acc.getAccNo()<<endl;
 os<<"Balance:"<<acc.getBalance()<<endl;
 return os;
}
Bank::Bank()
{
 
 Account account;
 ifstream infile;
 infile.open("Bank.data");
 if(!infile)
 {
 //cout<<"Error in Opening! File Not Found!!"<<endl;
 return;
 }
 while(!infile.eof())
 {
 infile>>account;
 accounts.insert(pair<long,Account>(account.getAccNo(),account));
 }
 Account::setLastAccountNumber(account.getAccNo());
 
 infile.close();
 
}
Account Bank::OpenAccount(string fname,string lname,float balance)
{
 ofstream outfile;
 Account account(fname,lname,balance);
 accounts.insert(pair<long,Account>(account.getAccNo(),account));
 
 outfile.open("Bank.data", ios::trunc);
 
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 outfile<<itr->second;
 }
 outfile.close();
 return account;
}
Account Bank::BalanceEnquiry(long accountNumber)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 return itr->second;
}
Account Bank::Deposit(long accountNumber,float amount)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 itr->second.Deposit(amount);
 return itr->second;
}
Account Bank::Withdraw(long accountNumber,float amount)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 itr->second.Withdraw(amount);
 return itr->second;
}
void Bank::CloseAccount(long accountNumber)
{
 map<long,Account>::iterator itr=accounts.find(accountNumber);
 cout<<"Account Deleted"<<itr->second;
 accounts.erase(accountNumber);
}
void Bank::ShowAllAccounts()
{
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
 }
}
Bank::~Bank()
{
 ofstream outfile;
 outfile.open("Bank.data", ios::trunc);
 
 map<long,Account>::iterator itr;
 for(itr=accounts.begin();itr!=accounts.end();itr++)
 {
 outfile<<itr->second;
 }
 outfile.close();
}
