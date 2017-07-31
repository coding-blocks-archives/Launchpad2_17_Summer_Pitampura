//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
using namespace std;

int arr[60];
int memo[60];

int maxVal(int be, int en, int k){
	if (be > en){
		return 0;
	}

	if (memo[be] != 0) return memo[be];

	int pick = maxVal(be + k + 1, en, k) + arr[be];
	int left = maxVal(be + 1, en, k);

	return memo[be] = max(pick, left);
}



int main(){
	int stalls;
	int step;
	char comma;

	cin >> stalls >> comma >> step;
	for(int i = 0; i < stalls; ++i){
		cin >> arr[i];
	}

	int ans = maxVal(0, stalls - 1, step);
	cout << ans;
	return 0;
}