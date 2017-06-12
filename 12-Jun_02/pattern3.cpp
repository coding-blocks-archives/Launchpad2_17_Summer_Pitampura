/*
1
2 3
4 5 6
7 8 9 10
*/
#include <iostream>
using namespace std;
int main(){
	//read no of lines
	int n; 	cin >> n;

	//print n lines
	int curline = 1;
	
	int val = 1;
	while(curline <= n){
		// print one line
		int nTerms = curline;
		int curTerm = 1;
		while(curTerm <= nTerms){
			cout << val;
			cout << " ";
			val = val + 1;
			curTerm = curTerm + 1;
		}
		cout << "\n";
		curline = curline + 1;
	}


}