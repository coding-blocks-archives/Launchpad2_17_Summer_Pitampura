//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;

	int ans = 0;	//represents the reversed number

	//while I have a --number-- digit I have to process it
	while (num > 0){
		int unitDigit = num % 10;
		//shift my ans so as to accomodate the new unitDigit
		ans = ans * 10;		//ans *= 10;
		ans += unitDigit;
		num /= 10;
	}

	cout << ans;	


}