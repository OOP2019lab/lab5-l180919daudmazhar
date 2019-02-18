#include "Header.h"


BankAccount::BankAccount(string username, int id)
{
	//Default Constructor//


	balancelimit = 200000;
	balance = 0;
	transactionsize = 10;
	transactions = new double[transactionsize];
	name = username;
	account_no = id;
	currentrans = 0;
}

void BankAccount::Print()
{
	cout << "The username is: " << name << endl;
	cout << "The id of the accountholder is: " << account_no << endl;
	cout << "The account balance is: " << balance << endl;
	cout << "The total no of transactions completed are: " << currentrans << endl;
	for (int i = 0; i < currentrans; i ++)
	{
		cout << transactions[i] << ", ";  //prints the transaction array//
	}

}

void BankAccount::WithDraw(int amount)
{
	if(currentrans == transactionsize)
	{
		increaseTranCapacity();
	}

	if (amount <= balance)
	{
		transactions[currentrans] = -amount;
		currentrans++;
		balance = balance - amount;
		cout << "Successful transaction \n";

	}
	else
		cout << "Transaction not successful. Insufficient Balance \n";
}

void BankAccount::Deposit(int amount)
{
	if(currentrans == transactionsize)  //checks the size of the transaction array//
	{
		increaseTranCapacity();
	}

	if (amount + balance <= balancelimit)  //checks the limit of the account//
	{
		transactions[currentrans] = amount;
		currentrans++;
	
		balance = balance + amount;
		cout << "Successful transaction \n";
	}
	else
	{
		cout << "Error. Balance limit reached! \n"; 
	}

}

void BankAccount::increaseTranCapacity()
{
	 //doubles the size of the transaction array//

	int newsize = transactionsize*2;      
	double *copy = new double[newsize];  //creates a copy pointer//
	for (int i = 0; i < transactionsize; i ++)
	{
		copy[i] = transactions[i];  //stores data in copy array//
	}
	delete[]transactions; //deletes the original array//
	transactions = nullptr;
	transactions = new double[newsize];   //creates another array and doubles the size of the original array//
	for (int i = 0 ; i < transactionsize; i ++)
	{
		transactions[i] = copy[i]; //copies data from the copy array to the original array again//
	}
	delete[]copy;
	copy = nullptr;
	transactionsize=newsize;

	cout << "Size Increased \n";
}

BankAccount::~BankAccount()
{
	//Destructor Function//

	balancelimit = 0;
	balance = 0;
	delete[]transactions;
	name = 'NULL';
	account_no = 0;
	currentrans = 0;

}