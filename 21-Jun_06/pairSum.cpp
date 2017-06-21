//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;

void input(int a[], int n){
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
}


void printPairs(int a[], int n, int sum){
	//for every element
	//do something : scan the remaining array
	//N^2

	for(int i = 0; i < n; ++i){
		// scan remaining arr
		int part1 = a[i];
		int part2 = sum - a[i];
		//scanning for part 2
		for(int j = i + 1; j < n; ++j){
			if (a[j] == part2){
				// pair found
				cout << part1 << " " << part2 << "\n";
			}
		}
	}
}

void bubbleSort(int arr[], int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - i; ++j){
			if(j + 1 < n && arr[j] > arr[j + 1]){
				//swap
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}


void printPairs_fast(int arr[], int n, int sum){
	//Time complexity N
	int i = 0;
	int j = n - 1;
	while(i < j){
		int calSum = arr[i] + arr[j];
		if (calSum == sum){
			cout << arr[i] << " " << arr[j] << endl;
			++i;
			--j;
		}
		else if (calSum > sum){
			--j;
		}
		else {
			++i;
		}
	}
}


int main(){
	int arr[100];
	int n;
	cin >> n;

	input(arr, n);

	cout << "Enter sum to be searched ";
	int sum;
	cin >> sum;

	// printPairs(arr, n, sum);
	bubbleSort(arr, n);
	printPairs_fast(arr, n, sum);
}