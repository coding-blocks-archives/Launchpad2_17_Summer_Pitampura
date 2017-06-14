//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	double i = 1000.00;
	char c = 'A';

	int ii = c;
	cout << ii << endl;

	char cc = (double)i;		//wrong...data overflow
	cout << cc << endl;	
	// cout << sizeof(char);

	int fah = 11;
	float cel = (float)5 / 9 * (fah - 32); 	//explicit typecast
	cout << cel;

}