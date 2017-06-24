//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

// int len(char arr[], int n){
// int n is not required
int len(char arr[]){
	int i = 0;
	while(arr[i] != '\0'){
		++i;
	}
	return i;
}

int main(){
	char arr[101];
	cin >> arr;		//input! cin knows how to handle it	
	int l = len(arr);
	cout << l << endl;

	cin >> arr;
	l = len(arr);
	cout << l << endl;

}