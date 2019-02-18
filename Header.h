#include <string>
#include <iostream>
using namespace std;

class BankAccount{

	string name;
	int account_no, currentrans, withdrawal;
	float balance, balancelimit;
	double *transactions;
	int transactionsize;

public:
	BankAccount(string name, int account_no );
	~BankAccount();
	void Print();
	void WithDraw(int amount);
	void Deposit(int amount);
	void increaseTranCapacity();  

};