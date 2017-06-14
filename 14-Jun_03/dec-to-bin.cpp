//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int num;
	cin >> num;
	int ans = 0;

	while (num > 0){
		int rem = num  % 2;
		ans = ans * 10 + rem;
		// cout << rem;		// printing NOT Desired
		num = num / 2;
	}	
	cout << ans;

}