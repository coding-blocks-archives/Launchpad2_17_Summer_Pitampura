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

	void operator+(int x) {
		// void addInt(int x){
		coefficients[0] += x;

	}

	void operator+(Polynomial& X) {
		//same like void addPolynomial(Polynomial& X)
		//resolved like P1.addPolynomial(P2)
		Polynomial tmp(*this);
		for (int i = 0; i <= degree; ++i) {
			coefficients[i] += X.coefficients[i];
		}

	}

	void print() {
		for (int i = 0; i <= degree; ++i) {
			cout << coefficients[i] << "(x" << i << ") + " ;
		}
		cout << endl;
	}
};




int main() {

	int n;

	cout << "Enter no of coefficients " << endl;
	cin >> n;
	Polynomial P1(n);
	P1.print();


	cout << "Enter degree " << endl;
	cin >> n;
	Polynomial P2(n);
	P2.print();

	P1 + P2;		//P1.operator+(P2);
	P1.print();
	P2.print();


}