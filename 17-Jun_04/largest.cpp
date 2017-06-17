//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int arr[100];
	int n;	//size
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	int infinity = 10000000;
	int largestSoFar = -infinity;	//sentinel

	// int largestSoFar = arr[0];
	for(int i = 0; i < n; ++i){
		if (largestSoFar < arr[i]){
			//I have a new largestSoFar
			//time to update largestSoFar
			largestSoFar = arr[i];

		}
	}
	cout << "Largest So Far " << largestSoFar << endl;
}	