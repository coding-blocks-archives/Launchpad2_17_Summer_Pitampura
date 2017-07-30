//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
using namespace std;

int memo[100][100];
//memo contains the maximum profit I can make by selling bottles [be, en]

int maxProfit(int price[], int be, int en, int year){
	if (be > en){
		return 0;
	}

	if (memo[be][en] != 0) return memo[be][en];

	// year = (en - be + 1)
	int right = maxProfit(price, be + 1, en, year + 1) + price[be] * year;
	int left = maxProfit(price, be, en - 1, year + 1) + price[en] * year;

	return memo[be][en] = max(right, left);
	// return memo[be][en];
}

int main(){
	int wine[] = {3, 5, 2, 1, 4};
	int n = 5;

	int ans = maxProfit(wine, 0, 4, 1);
	cout << ans;

}