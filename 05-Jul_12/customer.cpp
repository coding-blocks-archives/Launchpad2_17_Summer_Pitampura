//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <cstring>
using namespace std;

class Customer{
private:
	int bal;
	char name[20];
	char phone[20];
	char account[20];

public:
	Customer(char n[], char acc[]){
		strcpy(name, n);
		strcpy(account, acc);

		bal  = 0;
		strcpy(phone, "");
	}

	//copy ctor
	//useless here....dafault ctor does the same thing
	Customer(const Customer& X){
		strcpy(account, X.account);
		bal = X.bal;
		
		strcpy(name, "");
		strcpy(phone, "");
	}

	void updatePhone(char p[]){
		strcpy(phone, p);
	}

	void printAcc(){
		cout << account << " " << bal << endl;
	}

	void operator+(int x){
	// void credit(int x){
		bal += x;
	}

	bool debit(int x){
		if (x < bal){
			bal -= x;
			return true;
		}
		return false;
	}

	void viewBal(){
		cout << bal << endl;
	}

	void print(){
		cout << account << "  " << name << " " << phone << " " << bal << endl;
	}

};


int main(){
	Customer C("Bill", "007");

	// C(1000);
	C + 1000;	//opeartor overloading
	C.print();

	// C.debit(2000);
	// C.updatePhone("123");

	Customer M(C);	//copy ctor invoked automatically
	M.print();

	M.debit(500);


	C.print();
	M.print();
}