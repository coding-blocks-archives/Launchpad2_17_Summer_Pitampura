//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>
using namespace std;

int strToNum(char arr[], int be, int en){
	if (be > en){
		return 0;
	}

	int smallerNum = strToNum(arr, be, en - 1);
	int curDig = arr[en] - '0';
	return smallerNum * 10 + curDig;
}



int main(){
	char str[100];
	cin >> str;

	int len = strlen(str);

	int num = strToNum(str, 0, len - 1);

	cout << num + 2;	
}