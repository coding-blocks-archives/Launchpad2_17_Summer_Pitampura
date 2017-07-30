//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <cstring>
using namespace std;

char s1[100];
char s2[100];
int n1, n2;

int memo[100][100];

//1 --> origin string
//2 --> destination string
int editDistance(int be1, int be2) {
	if (be1 == n1) {
		return n2 - be2;	//insert these many characters to s1
	}

	if (be2 == n2) {
		return n1 - be1;	//delete these many chars from s1
	}

	if (memo[be1][be2] != -1) return memo[be1][be2];

	if (s1[be1] == s2[be2]) {
		return memo[be1][be2] = editDistance(be1 + 1, be2 + 1);
	}

	int insertOp = editDistance(be1 , be2 + 1);
	int deleteOp = editDistance(be1 + 1, be2);
	int replace = editDistance(be1 + 1, be2 + 1);

	return memo[be1][be2] = 1 + min(insertOp, min(deleteOp, replace));
}


int main() {
	cin >> s1 >> s2;
	n1 = strlen(s1);
	n2 = strlen(s2);
	for(int i = 0; i < n1; ++i){
		for(int j = 0; j < n2; ++j){
			memo[i][j] = -1;
		}
	}
	int ans = editDistance(0, 0);

	cout << ans;

}