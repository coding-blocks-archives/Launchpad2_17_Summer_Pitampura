//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

int fib(int n){
	if(n == 0){
		return 0;
	}

	if (n == 1){
		return 1;
	}


	int ans = fib(n - 1) + fib(n - 2);	//recurrence
	//prev fibonacci will be obtained automatically
	//How?? via recursion
	return ans;
}


int main(){
	int n;
	cin >> n;
	int res = fib(n);	
	cout << res;
}