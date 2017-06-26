//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void printAsc(int n){
	if (n <= 0){
		return ;
	}

	printAsc(n - 1);
	cout << n << " ";
}



int main(){
	int n;
	cin >> n;
	printAsc(n);	
}