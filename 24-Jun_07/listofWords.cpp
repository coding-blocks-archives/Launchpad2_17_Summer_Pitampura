//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

bool matches(char word1[], char word2[]){
	int i = 0;
	while(word1[i] != '\0' && word2[i] != '\0'){
		if(word1[i] != word2[i]){
			return false;
		}
		++i;
	}

	if(word1[i] == '\0' && word2[i] == '\0')	return true;
	else return false;
}


bool doesExist(char listWords[][100], char word[], int n){
	for(int i = 0; i < n; ++i){
		if (matches(listWords[i], word)){
			return true;
		}
	}
	return false;
}


int main(){
	char listWords[100][100];

	int N;
	cin >> N;	//to read no of words

	//reading n words
	for(int i = 0; i < N; ++i){
		cout << "Word " << (i + 1) << " ";
		cin >> listWords[i];	//1D array
	}

	char word[100];
	cout <<"Enter word to search ";
	cin >> word;
	
	bool ans = doesExist(listWords, word, N);
	cout << ans;

}