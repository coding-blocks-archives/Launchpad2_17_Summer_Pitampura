//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <string>
using namespace std;

const char keypad[][10] = {
	" ", "?", "abc", "def",
	"ghi", "jkl", "mno",
	"pqrs", "tuvw", "xyz"
};


//helper method
void myPossibleCodes(char str[], int be, char code[], int i) {
	if (str[be] == '\0') {
		code[i] = '\0';
		cout << code << endl;
		return;
	}

	int idx = str[be] - '0';
	const char* keypadCode = keypad[idx];
	// const char& keypadCode = keypad[idx];

	//for every char in keypad code, I have to do something
	for (int k = 0; keypadCode[k] != '\0'; ++k) {
		code[i] = keypadCode[k];
		myPossibleCodes(str, be + 1, code, i + 1);
	}

}


void possibleCodes(char str[]) {
	char code[10] = {} ;
	myPossibleCodes(str, 0, code, 0);
}


int main() {
	char inp[10];
	cin >> inp;

	possibleCodes(inp);

}