//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int nlines;
	cin >> nlines;

	//specific program ---Not to be done
	// cout << "* *** *** *\n";
	// cout << "** ** ** **\n";
	// cout << "*** * * ***\n";	

	for(int row = 1; row <= nlines; ++row){
		//print row stars
		for(int star = 1; star <= row; ++star){
			cout << '*';
		}

		//print space
		cout << " ";

		//print nlines - row + 1 stars
		int starsToBePrinted = nlines - row + 1;
		for(int star = 1; star <= starsToBePrinted; ++star){
			cout << "*";
		}

		// print space
		cout << " ";

		//step3
		//print nlines - row + 1 stars
		// int starsToBePrinted = nlines - row + 1;	---cant be declared because it
		//exists already
		for(int star = 1; star <= starsToBePrinted; ++star){
			cout << "*";
		}

		//print space
		cout << " ";

		//step 1
		//print row stars
		for(int star = 1; star <= row; ++star){
			cout << '*';
		}

		cout << endl;

	}
}