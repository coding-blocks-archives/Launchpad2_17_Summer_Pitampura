//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>
using namespace std;

void myPrint(char s[], int be, int en){
	//prints [be, en]
	while(be <= en){
		cout << s[be];
		++be;
	}
}



void printSubstrings(char s[]){
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		// for(int j = i; j < strlen(s); ++j){
		//should be avoided since stelen is computed many times
		for(int j = i; j < len; ++j){
			myPrint(s, i, j);
			cout << endl;
		}
	}
}

int main(){
	char s[100];
	cin >> s;

	printSubstrings(s);
	return 0;	
}