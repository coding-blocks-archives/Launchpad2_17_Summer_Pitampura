//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

class Square {

public:
	int dim;
	Square() {
		cout << "Inside Empty Ctor Square()\n";
		dim = 0;
	}

	Square(const Square& X) {
		cout << "Inside Copy Ctor Square(Square& X)\n";
		dim = X.dim;
	}

	Square add(Square X) {
		cout << "Inside add" << endl;
		Square tmp(*this);
		// cout << "I win\n";
		tmp.dim = dim + X.dim;
		return tmp;
	}

	Square& operator=(const Square& S) {
		Square tmp;
		cout << "Inside operator= \n";
		dim = S.dim;
		return *this;
		// return tmp;
	}

};



int main() {
	Square S1;
	Square S2;

	// Square S3(S1.add(S2));	//move ctor called
	// Square S3 = S1.add(S2);	//same as above line

	Square S3;
	// cout << "Class confused :(\n";
	// S3.dim = 5;

	S3 = S2 = S1;	//S3.operator = (S2.operator = (S1));
	Square S3 = S2 = S1;		//S3(S2.operator=(S1));---initialisation hence copy ctor





}