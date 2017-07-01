//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;
const int N = 40;

bool canPlace(int board[][N], int x, int y){
	//check along the row
	// for(int i = 0; i < N; ++i){
	// 	if (board[x][i] == 1) return false;
	// }	//--redundant

	//checking along the col
	for(int i = 0; i < N; ++i){
		if (board[i][y] == 1) return false;
	}

	//checking left diagonal
	int i = x - 1;
	int j = y - 1;
	while(i >= 0 && j >=0){
		if(board[i][j] == 1) return false;
		--i;
		--j;
	}

	//checking the right diagonal
	i = x - 1;
	j = y + 1;
	while(i >= 0 && j < N){
		if (board[i][j] == 1) return false;
		--i;
		++j;
	}
	return true;
}

void print(int board[][N], int n = N){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


bool queen(int board[][N], int cRow){
	if (cRow == N){
		//This means we have filled the whole board
		print(board, N);
		return true;	//Yippie! I have found a solution
	}

	//try placing a queen in each column of the current row cRow
	for(int col = 0; col < N; ++col){
		if (canPlace(board, cRow, col) == true){
			//Oh Yes! I can place the queen in this CELL
			//OK!! I WILL place and ask recursion to find the sol
			board[cRow][col] = 1;		//Placement done!!
			
			bool ask = queen(board, cRow + 1);
			if (ask == true){
				return true;	//No need to look anymore
				//Our decision of placing queen at {cRow, col} was perfect!
			}

			//Oops! Recursion wasn't able to find a solution with current config
			//restore the original state, i.e., remove the PLACED queen
			board[cRow][col] = 0;		//Queen removed
		}
	}

	//I have tried all col for the cur row but can't find a sol...so no sol
	return false; 
}

int main(){
	int board[N][N] = {};
	queen(board, 0);
}