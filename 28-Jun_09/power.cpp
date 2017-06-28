//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;

int power(int x, int n){
	if (x == 0) return 0;
	if (n == 0)	return 1;

	int smallerPower = power(x, n - 1);
	int ans = smallerPower * x;
	return ans;

	// return power(x, n - 1) * x;
}

int main(){
	int n;
	int x;
	cin >> x >> n;
	int ans = power(x, n);	
	cout << ans;
}