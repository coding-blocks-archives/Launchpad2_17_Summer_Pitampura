//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;
//TODO : DO it for all characters and also in N^2/NlogN


bool isPermutation(char s1[], char s2[]){
	int cnt[26] = {};	//initialise to zero---MUST--hack

	int i = 0;
	//setting cnt
	while(s1[i] != '\0'){
		char curChar = s1[i];
		int idx = curChar - 'a';
		++cnt[idx];
		++i;
	}

	//unsetting cnt
	i = 0;
	while(s2[i] != '\0'){
		--cnt[s2[i] - 'a'];
		++i;
	} 

	//checking that cnt is all zero
	bool ans = true;
	for(int i = 0; i < 26; ++i){
		if (cnt[i] != 0){
			ans = false;
			break;
		}
	}

	return ans;
}


int main(){
	char s1[100];
	char s2[100];

	cin >> s1 >> s2;

	bool ans = isPermutation(s1, s2);
	cout << ans;
}