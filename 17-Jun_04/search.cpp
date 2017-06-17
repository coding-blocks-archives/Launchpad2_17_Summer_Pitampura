//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;
int main() {
	int arr[10];
	int sze;
	cin >> sze;

	for (int i = 0; i < sze; ++i){
		cin >> arr[i];
	}

	int numToSearch;
	cin >> numToSearch;

	//for element, I will check
	for(int i = 0; i < sze; ++i){
		if (arr[i] == numToSearch){
			cout << i;
			break;
		}
	}
}