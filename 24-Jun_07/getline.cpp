//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;
int main(){
//getline demo
	char a[100];
	// cin.getline(a, 20);
	cin.getline(a, 20, '$'); //delimiter;
	cout << "X" << a << "X";

	cin.clear();		//resetting the cin

	char b[20];
	cin.getline(b, 20, '#');
	cout << "X" << b << "X";

	int x;
	cin >> x;







}