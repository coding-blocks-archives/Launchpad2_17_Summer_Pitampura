#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	int ndigit = 0;

	//while num is not zero ==> num has digits
	while(num > 0){
		//do something--> rem & quo
		// int rem = num % 10;
		// int newNum = num / 10;
		num = num / 10;
		++ndigit;
		// num = newNum;
	}

	cout << ndigit << "\n";
}