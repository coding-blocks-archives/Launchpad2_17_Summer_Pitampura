#include <iostream>
using namespace std;

#include "contract.h"	//important to use add and subtarct in line 14,15

int main(){
	char ch;
	int ans;

	cin >> ch;


	switch(ch){
		case '+' : ans = add(2, 3); break;
		case '-' : ans = subtract(2,3);
	}

	cout << ans;
}