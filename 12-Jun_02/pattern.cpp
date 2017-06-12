/*
     1
    123
   12345
  1234567
 123456789
*/
#include <iostream>
using namespace std;
int main(){
	//read N
	int n; cin >> n;
	//curline  = 1
	int curline = 1;
	//while curline <= n
	while (curline <= n){
		
		//print spaces
		//space=1
		int space = 1;
		//while space <= n - curline
		while (space <= n - curline){
			//print space
			cout << " ";
			space = space + 1;
		}

		//print values
		//val = 1
		int val = 1;
		int nVal = 1;
		// while nval <= 2 * curline - 1
		while (nVal <= 2*curline -1){
			// print val
			cout << val;
			val = val + 1;
			nVal = nVal + 1;
		}
		//print enter
		cout << "\n";
		curline = curline + 1;
	}
}













