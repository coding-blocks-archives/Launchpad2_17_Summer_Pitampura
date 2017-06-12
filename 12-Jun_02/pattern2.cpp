/*
    1
   232
  34543
 4567654
567898765
*/
#include <iostream>
using namespace std;
int main() {
	//read N
	int N; cin >> N;

	//curLine = 1
	int curLine = 1;

	while (curLine <= N) {
		//do something
		//print spaces
		//space = 1
		int space = 1;
		while (space <= N - curLine) {
			// print space
			cout << " ";
			space = space + 1;
		}

		//print val
		int nVal = 1;
		int val = curLine;
		// forward is true ----Assumption
		bool forward = true;

		while (nVal <= 2 * curLine - 1) {
			cout << val;
			nVal = nVal + 1;
			if (val == 2 * curLine - 1) {
				//assumption break down
				forward = false;
			}
			//update val as per forward
			// if forward is true; increament value
			if (forward == true) {
				val = val + 1;
			}
			else {
				val = val - 1;

			}
		}
		cout << "\n";
		curLine = curLine + 1;
	}
}