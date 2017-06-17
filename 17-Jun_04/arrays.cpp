//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main() {

	// int roll[5];	//array of 5 integers, definition/declaration

	// cout <<roll[0] << endl;	//????

	//can I initialise an array. Yes! I can
	int roll[5] = {11, 21, 23, 2, -1};

	int roll[] = {11, 21, 23, 2, -1};	//size can be omitted while initialisation

	// int roll[5] = {};	//all values are 0
	// cout << roll[0] << endl;	//????


	// cin >> roll;	--intention but can't do
	//since roll is name

	// for (int i = 0; i <= 4; ++i) {
	// 	cin >> roll[i];
	// }

	//printing
	for (int i = 0; i < 5; ++i) {
		cout << roll[i] << " ";
	}

}