//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void printDesc(int n){
/*
This function PRINTS n numbers in descending order
*/
	if (n < 0) {
		// for n less than zero, recurrence doesn't hold
		return ;
	}

	//let us print one number ourself
	cout << n << endl;

	//the remaining numbers will be printed automatically. But How?? Via recursion
	printDesc(n - 1);	//recurrence relation
}


int main(){
	int n;
	cin >> n;
	printDesc(n);	
}