//Deepak Aggarwal, Coding Blocks
#include <iostream>
#include <cmath>
using namespace std;
const int N = 9;

void print(int board[][N], int n = N){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isValid(int board[][N], int x, int y, int num){
	//if {x,y} position is already filled-->fixed cell
	// if (board[x][y] != 0)	return false;

	for(int i = 0; i < N; ++i){
		if (board[x][i] == num)	return false;	//found along row
		if (board[i][y] == num) return false;	//found along col
	}

	//checking in the Block
	int n = sqrt(N);
	int sr = x / n * n;
	int er = sr + n;
	for(; sr < er; ++sr){
		int sc = y / n * n;
		int ec = sc + n;
		for(; sc < ec; ++sc){
			if (board[sr][sc] == num)	return false;
		}
	}

	return true;
}

bool sudokuSolver(int board[][N], int x, int y){
	if (x == N){
		//all above rows are already filled
		print(board);
		return true;
	}

	if (y == N){
		//time for a new Row
		return sudokuSolver(board, x + 1, 0);
	}

	if (board[x][y] != 0) return sudokuSolver(board, x, y + 1);
	
	//we are at some x,y cell
	for(int num = 1; num <= N; ++num){
		//does num and x,y forms a valid combination??
		if (isValid(board, x, y, num) == true){
			board[x][y] = num;

			bool ask = sudokuSolver(board, x, y + 1);
			if (ask == true) return true;

			board[x][y] = 0;	//restore the previous changes
		}
	}

	return false;
}



int main(){
	int board[N][N] = 
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

    sudokuSolver(board, 0, 0);
}