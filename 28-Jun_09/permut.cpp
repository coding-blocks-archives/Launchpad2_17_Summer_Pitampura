//Deepak Aggarwal, Coding Blocks
#include <string>
#include <iostream>
using namespace std;
int cnt = 0;

void printPermutation(string s, string decision){
	//print permuatation prints all the permutations of a string s after appending them
	//to res

	if(s.size() == 0){
		cout << ++cnt << " " << res << endl;
		return ;
	}

	for(int i = 0; i < s.size(); ++i){
		string rem = s.substr(0, i) + s.substr(i + 1);
		string modifiedDecision = decision + s[i];
		printPermutation(rem, newRes);
	}
}



int main(){
	string s;
	cin >> s;

	printPermutation(s, "");
}