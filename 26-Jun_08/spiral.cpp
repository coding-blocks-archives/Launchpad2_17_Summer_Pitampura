//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void input(int arr[][10], int M, int N) {
	for (int r = 0; r < M ; ++r) {
		cout << "Enter row " << r + 1 << " with idx " << r << "\n";
		for (int c = 0; c < N; ++c) {
			cin >> arr[r][c] ;
		}
	}
}

void printMat(int arr[][10], int M, int N) {
	for (int r = 0; r < M ; ++r) {
		// cout << "Enter row " << r + 1 << " with idx " << r << "\n";
		for (int c = 0; c < N; ++c) {
			cout << arr[r][c] << " ";
		}
		cout << endl;

	}
}


void spiral(int mat[][10], int M, int N) {
	int left = 0;
	int right = N - 1;
	int top = 0;
	int bottom = M - 1;

	while (left <= right || top <= bottom) {
		//print the top row
		if (top <= bottom) {
			//this check is important since it might happen that left is less than or equal to
			//right but top is greater than equal to bottom
			for (int c = left; c <= right; ++c) {
				cout << mat[top][c] << " ";
			}
			++top;
		}

		//print last col
		if (left <= right) {
			for (int r = top; r <= bottom; ++r) {
				cout << mat[r][right] << " ";
			}
			--right;
		}

		//print bottom row
		if (top <= bottom) {
			for (int c = right; c >= left; --c) {
				cout << mat[bottom][c] << " ";
			}
			--bottom;
		}

		//print left col
		if (left <= right) {
			for (int r = bottom; r >= top; --r) {
				cout << mat[r][left] << " ";
			}
			++left;
		}
	}
}



int main() {
	int mat[10][10];
	int M, N;
	cout << "M N";
	cin >> M >> N;

	input(mat, M, N);
	printMat(mat, M, N);

	spiral(mat, M, N);

	return 0;	//0 for successful termination
}