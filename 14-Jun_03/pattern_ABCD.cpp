//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int nLines;
	cin >> nLines;

	for(int row = 1; row <= nLines; ++row){
		//think of printing just 1 line
		int nChar = 2 * (nLines - row + 1);

		//Increasing Order printing
		char c = 'A';		//val to print 
		for(int cc = 1; cc <= nChar / 2; ++cc){
			cout << c;
			c = c + 1;		//next char to c
		}

		//Decrement 
		char rev_c = 'A' + (nChar / 2) - 1;
		for(int cc = 1; cc <= nChar / 2; ++cc){
			cout << rev_c;
			--rev_c;
		}
		cout << endl;
	}
}