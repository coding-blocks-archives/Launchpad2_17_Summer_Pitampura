//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <string>
using namespace std;

void printSub(string s, string decision){
	//printSub PRINTS all the subsequences of string s appended
	//to string decision
	if (s.size() <= 0){
		cout << decision << endl;
		return;
	}

	// 'a' excluded from "abc", hence "bc"
	string excluding = s.substr(1);	//I am not taking 'a'
	printSub(excluding, decision);

	decision += s[0];	//"a" taken as decision
	printSub(excluding, decision);
}

void printSub1(char str[], int be, char decision[], int i){
	if (str[be] == '\0'){
		decision[i] = '\0';
		cout << decision << endl;
		return;
	}

	printSub1(str, be + 1, decision, i);	//excluding be char
	decision[i] = str[be];
	printSub1(str, be + 1, decision, i + 1);	//including be char as part of decision
}



int main(){
	// string s;
	// cin >> s;
	// printSub(s, "");

	char str[10];
	cin >> str;
	char decision[10] = "";
	printSub1(str, 0, decision, 0);	
}