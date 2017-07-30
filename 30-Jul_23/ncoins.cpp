//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
using namespace std;
const int inf = 10000000;

int memo[110];	//default 0 initialised

int change(int coins[], int n, int val){
	if (val < 0) {
		return inf;
	}

	if (val == 0) return 0;

	if (memo[val] != 0) return memo[val];

	int best = inf;
	//let's pick every possible coin and check for minimum
	for(int i = 0; i < n; ++i){
		int curCoin = coins[i];
		if (curCoin > val) continue;
		int curAns = 1 + change(coins, n, val - curCoin);
		best = min(curAns, best);
	}

	return memo[val] = best;
}

int main(){
	int coins[] = {1, 3, 5, 6, 8};
	int n = 5;		//size of coins[]
	
	int val;
	cin >> val;

	int ans = change(coins, n, val);
	cout << ans;
	
}