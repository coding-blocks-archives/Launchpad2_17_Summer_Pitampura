//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void concatenate(char s1[], char s2[]){
	int i = 0;
	while(s1[i] != '\0'){
		++i;
	}

	int j = 0;
	while(s2[j] != '\0'){
		s1[i] = s2[j];
		++i;
		++j;
	}

	s1[i] = '\0';
}



int main(){
	char s1[100];
	char s2[50];
	
	cin >> s1 >> s2;

	concatenate(s1, s2);
	cout << s1 << endl;	
}