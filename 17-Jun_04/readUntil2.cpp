//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	char c;
	cin >> c;
	int n = 0;
	while (c != '$'){
		cout << c;
		++n;
		cin >> c;
	}	
	cout << endl;
	cout << "No of char are " << n << endl;
}