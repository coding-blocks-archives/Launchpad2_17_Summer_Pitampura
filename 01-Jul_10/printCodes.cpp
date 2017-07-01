//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void printCodes(char str[], int be, char code[], int i){
	//prints ALL the possible codes of str starting from be
	//after appending them to code starting at i---redundant

	if (str[be] == '\0'){
		code[i] = '\0';		//Important
		cout << code << endl;
		return;
	}


	//handling just '1' in "123"
	int num = str[be] - '0';	//'1' has become 1
	char cur = 'a' + num - 1;
	code[i] = cur;
	printCodes(str, be + 1, code, i + 1);

	//handling "12" in "123"
	if (str[be + 1] == '\0') return;

	int num2 = 10 * (str[be] - '0') + str[be + 1] - '0';

	if (num2 > 26) return;
	char cur2 = 'a' + num2  - 1;
	code[i] = cur2;
	printCodes(str, be + 2, code, i + 1);
}


int main(){
	char str[100];
	char code[100] = "";
	cin >> str;

	printCodes(str, 0, code, 0);	
}