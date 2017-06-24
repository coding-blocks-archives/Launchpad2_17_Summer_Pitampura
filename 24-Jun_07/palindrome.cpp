//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int length(char arr[]){
	int i = 0;
	//char arr are null terminated
	while(arr[i] != '\0'){
		++i;
	}
	return i;
}

bool checkPalindrome(char str[]){
	int len = length(str);

	int i = 0; 
	int j = len - 1;	//j is index
	bool isPalindrome = true;
	while(i < j){
		if (str[i] != str[j]){
			//found a mismatch
			isPalindrome = false;
			//no need to process furthur
			break;
		}
		++i;
		--j;
	}
	return isPalindrome;
}



int main(){
	char str[100];
	cin >> str;

	bool ans = checkPalindrome(str);
	cout << boolalpha << ans << endl;
	//boolalpha to prints bool as alphabets	
}