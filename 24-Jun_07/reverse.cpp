//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>		//to use strlen
#include <algorithm> 	//to use swap
using namespace std;

void mySwap(char& x, char& y){
	//pass by reference is MUST
	char tmp = x;
	x = y;
	y = tmp;
}


void myReverse(char s[]){
	int j = strlen(s) - 1;
	int i = 0;
	while(i < j){
		//swap char
		// mySwap(s[i], s[j]);
		swap(s[i], s[j]);
		++i;
		--j;
	}
}


int main(){
	char s[100];
	cin >> s;

	myReverse(s);

	cout << s << endl;
}