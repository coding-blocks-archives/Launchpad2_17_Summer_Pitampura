#include <iostream>
using namespace std;

//input a matrix
void input(int arr[][10], int M, int N) {
	for (int r = 0; r < M ; ++r) {
		cout << "Enter row " << r + 1 << " with idx " << r << "\n";
		for (int c = 0; c < N; ++c) {
			cin >> arr[r][c] ;
		}
	}
}

//output a matrix
void output(int arr[][10], int M, int N) {
	for (int r = 0; r < M ; ++r) {
		// cout << "Enter row " << r + 1 << " with idx " << r << "\n";
		for (int c = 0; c < N; ++c) {
			cout << arr[r][c] << " ";
		}
		cout << endl;

	}
}
