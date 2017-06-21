//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;

void input(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

int binarySearch(int arr[], int n, int key) {
	//Assumption: arr is sorted
	//searches an element Key and returns the position/index corresponding to it
	//If not found -1 is returned
	int be = 0;
	int en = n - 1;
	while (be <= en) {
		int mid = (be + en) / 2;

		if (arr[mid] == key) {
			//Great! We have found the key
			return mid;
		}
		else if (arr[mid] < key) {
			//Element will lie in the right
			be = mid + 1;
		}
		else {
			//Element will lie in the left
			en = mid - 1;
		}
	}
	//I have scanned the whole array! Element is not present
	return -1;
}

int main() {
	int arr[100];
	int n;
	cin >> n;

	input(arr , n);

	int valToSearch;
	cout << "valToSearch ";
	cin >> valToSearch;

	int pos = binarySearch(arr, n, valToSearch);

	cout << "Value present at " << pos;
}
