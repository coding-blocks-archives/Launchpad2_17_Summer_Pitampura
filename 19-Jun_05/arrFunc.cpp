//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void update(int a[], int be, int en){
	for(int i = be; i <= en; ++i){
		a[i] = a[i] + 1;
	}
}

int main(){
	int arr[] = {1,2,3};
	update(arr, 0, 2);

	for(int i = 0; i < 3; ++i){
		cout << arr[i] << " ";
	}

}