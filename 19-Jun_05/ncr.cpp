//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

int factorial(int n){
	int fact = 1;
	for(int i = 1; i <= n; ++i){
		fact = fact * i;
	}
	return fact;
}


int ncr(int n, int r){
	int ans = factorial(n) / (factorial(r) * factorial(n - r));
	return ans;
}

int main(){
	// int n;
	// cin >> n;	
	// // int fact = factorial(n);
	// int r;
	// cin >> r;
	// int ncr_value = ncr(n, r);	//calling 
	// cout << ncr_value;

	int ans = factorial(5);
	cout << ans;
}