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

void mycopy(char to[], char from[]){
	int i = 0;
	while(from[i] != '\0'){
		to[i] = from[i];
		++i;
	}
	to[i] = '\0';
}

int main(){
	int N;
	cin >> N;
	cin.get();	//to read/eject "enter" from buffer/stream/file

	char s[100];

	int larLen = 0;
	char largest[100];
	int curStr = 0;
	
	for(int i = 0; i < N; ++i){
		//read a string
		//calc length
		//update largest
		cout << "Enter str " << ++curStr << " ";
		cin.getline(s, 99);
		int curLen = length(s);

		if (curLen > larLen){
			larLen = curLen;
			mycopy(largest, s);
		}
	}	

	cout << "Largest Length is " << larLen << endl;
	cout << "Largest String is " << largest << endl;
}