//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <cstring>
using namespace std;

void rotate(char s[], int k){
	char tmp[100];	//assumption
	int n = strlen(s);
	k = k % n;

	//copy last k char 
	int j = 0;	//corresponding to tmp
	for(int i = n - k; i < n; ++i){
		tmp[j] = s[i];
		++j;
	}

	//shift first n-k char to end
	int lastIndx = n - 1;
	for(int i = n - k - 1; i >= 0; --i){
		s[lastIndx] = s[i];
		--lastIndx;
	}	

	//copy tmp into s
	for(int i = 0; i < k; ++i){
		s[i] = tmp[i];
	}

}

int main(){
	char s[100];
	int k;
	cout << "Enter K ";
	cin >> k;	

	cout << "Enter String ";
	cin >> s;

	rotate(s, k);

	cout << "Rotated String is " << s << endl;
}