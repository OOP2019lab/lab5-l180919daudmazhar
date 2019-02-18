// 18l0919 Lab 5.cpp : Defines the entry point for the console application.
//


#include "Header.h"
#include <iostream>
using namespace std;



int main()
{
	int id = 549002, amount = 10000;
	string username = "John Doe";
	BankAccount myAccount(username, id);
	//myAccount.Print();
	myAccount.Deposit(amount);
	myAccount.WithDraw(500);
	//myAccount.Print();
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Deposit(amount);
	myAccount.Print();
	return 0;
}

