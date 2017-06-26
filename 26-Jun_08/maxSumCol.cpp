//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <algorithm>
#include "myio.h"
using namespace std;

int maxSum(int mat[][10], int M, int N){
	int maxRow = -10000;

	//for rows
	for(int row = 0; row < M; ++row){
		int curRowSum = 0;
		for(int col = 0; col < N; ++col){
			curRowSum += mat[row][col];
		}
		if (curRowSum > maxRow){
			maxRow = curRowSum;
		}
	}

	//for cols
	int maxColSum = -10000;
	for(int col = 0; col < N; ++col){
		int curSum = 0;
		for(int row = 0; row < M; ++row){
			curSum += mat[row][col];
		}
		maxColSum = max(maxColSum, curSum);
	}

	int ans = max(maxRow, maxColSum);
	return ans;
}

//traversing just once

int myMax_element(int rowSum[], int colSum[]){
	int ans = -100000;
	//rowSum checked
	for(int i = 0; i < 10; ++i){
		ans = max(ans, rowSum[i]);
	}

	//colSum checked
	for(int i = 0; i < 10; ++i){
		ans = max(ans, colSum[i]);
	}
}

int maxSum2(int mat[][10], int M, int N){
	int rowSum[10] = {};
	int colSum[10] = {};

	for(int row = 0; row < M; ++row){
		for(int col = 0; col < N; ++col){
			//element is iterated once; and corresponding sum is set accordingly
			rowSum[row] += mat[row][col];
			colSum[col] += mat[row][col];
		}
	}

	int ans = myMax_element(rowSum, colSum);
	return ans;
}


int main(){
	int mat[10][10];
	int M, N;
	cin >> M >> N;

	input(mat, M, N);
	output(mat, M, N);

	int sum = maxSum2(mat, M, N);
	cout << "Sum is " << sum << endl;
}