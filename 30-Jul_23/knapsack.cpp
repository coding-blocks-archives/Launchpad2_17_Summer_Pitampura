//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

int memo[110][1010];

int price[] = {100, 80, 30, 50};
int wt[] = {2, 3, 5, 10};

int maxValue(int be, int en, int k){
	if (be > en) return 0;
	
	if (k <= 0) return 0;

	if (memo[be][k] != 0) return memo[be][k];

	//item picked
	int pick = -100000;
	if (wt[be] <= k) pick = maxValue(be + 1, en, k - wt[be]) + price[be];
	
	//item left
	int left = maxValue(be + 1, en, k);

	return memo[be][k] = max(pick, left);
}



int main(){
	int k; 
	cin >> k;
	int ans = maxValue(0, 3, k);
	cout << ans;
	
}