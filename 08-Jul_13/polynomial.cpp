//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

class Polynomial{
	int * coefficients;
	int degree;
public:
	Polynomial(int n) {
		coefficients = new int[n];
		degree = n - 1;
		//input coefficients
		cout << "Enter coefficients\n";
		for (int i = 0; i < n; ++i) {
			cin >> coefficients[i];
		}
	}

	~Polynomial(){
		delete[] coefficients;
	}

	Polynomial(const Polynomial& P) {
		//deep copying
		// coefficients = P.coefficients;		NO!! NO!!
		degree = P.degree;
		coefficients = new int[degree + 1];

		//copying the arr
		for (int i = 0; i <= degree; ++i) {
			coefficients[i] = P.coefficients[i];
		}
	}

	int evaluate(int x) {
		int res = 0;
		int xpow = 1;

		for (int i = 0; i <= degree; ++i) {
			res = res + coefficients[i] * xpow;
			xpow = xpow * x;
		}

		return res;
	}

	Polynomial operator+(int x) {
		// void addInt(int x){
		// coefficients[0] += x;

		//data memebers should not be updated but a new Polynomial should be returned
		
		// Polynomial tmp(X.degree + 1);
		//copy coefficients of X into tmp

		// Polynomial * ptr = this;
		Polynomial tmp(*this);	//this is a ptr to P1

		tmp.coefficients[0] += x;
		return tmp;

	}

	// void operator+(Polynomial& X) {
	// 	//same like void addPolynomial(Polynomial& X)
	// 	//resolved like P1.addPolynomial(P2)
	// 	Polynomial tmp(*this);
	// 	for (int i = 0; i <= degree; ++i) {
	// 		coefficients[i] += X.coefficients[i];
	// 	}

	// }

	Polynomial operator+(Polynomial& X){
		Polynomial tmp(*this);

		for(int i = 0; i <= X.degree; ++i){
			tmp.coefficients[i] += X.coefficients[i];
		}

		return tmp;
	}


	void print() {
		for (int i = 0; i <= degree; ++i) {
			cout << coefficients[i] << "(x" << i << ") + " ;
		}
		cout << endl;
	}

	// void operator<<(ostream& printer){
	// 	printer << degree;
	// }
	friend ostream& operator<<(ostream& printer, const Polynomial& P);
	//violates OOPS
	//freind functions are NOT data members
	// friend functions CAN access private data members

};

ostream& operator<< (ostream& printer, const Polynomial& P){
	cout << P.degree;
	return printer;
}


int main() {
	Polynomial P1(5);
	// P1 << cout;
	cout << P1 << P1;
	// int n;


	// cout << "Enter no of coefficients " << endl;
	// cin >> n;
	// P1.print();

	// Polynomial X = P1 + 2;
	// P1.print();
	// X.print();
	
	// P1.operator+(2); //P1 + 2 // P1.plus(2)

	// cout << "Enter degree " << endl;
	// cin >> n;
	// Polynomial P2(n);
	// P2.print();

	// P1 + P2;		//P1.operator+(P2);
	// P1.print();
	// P2.print();


	//testing P1 + P2
	// Polynomial P1(5), P2(4);
	// Polynomial P3 = P1 + P2;
	// P3.print();

}