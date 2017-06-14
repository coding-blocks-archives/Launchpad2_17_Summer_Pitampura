//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int nLines;
	cin >> nLines;

	//nLines HAS TO BE printed---so for loop
	for(int curLine = 1; curLine <=nLines; ++curLine){
		int nChar = curLine;
		//printing nchar
		
		int val = 1;

		if (curLine % 2 == 0){
			val = 0;
		}

		for(int curChar = 1; curChar <= nChar; ++curChar){
			cout << val;
			if (val == 0){
				val = 1;
			}
			else {
				val = 0;
			}
			// val = 1 - val;
		}
		cout << endl;
	}	
}