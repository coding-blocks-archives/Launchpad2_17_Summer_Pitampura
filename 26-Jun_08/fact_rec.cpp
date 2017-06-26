//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

int factorial(int n){
	//base cases
	if (n == 0){
		return 1;
	}

	int nMinus1 = factorial(n - 1);	//hypothesis : Recursion always function
	// int ans = nMinus1 * n;
	int ans = factorial(n - 1) * n;	//recurrence relation
	return ans;
}


int main(){
	int n; cin >> n;
	int ans = factorial(n);
	cout << ans << endl;
	
}