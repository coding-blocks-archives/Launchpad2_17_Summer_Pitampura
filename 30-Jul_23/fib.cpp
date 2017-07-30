//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <algorithm>
#include <iostream>
using namespace std;

// #define int long long

int memo[1010];

int fib(int n){
	if (n <= 0) return 0;

	if (n == 1) return 1;

	if (memo[n] != -1){
		return memo[n];
	}

	memo[n] = fib(n - 1) + fib (n - 2);
	return memo[n];
}

main(){		//no return type means by default int 
	int n;
	cin >> n;

	//setting -1
	fill(memo, memo + n + 1, -1);

	int ans = fib(n);
	cout << ans;
}