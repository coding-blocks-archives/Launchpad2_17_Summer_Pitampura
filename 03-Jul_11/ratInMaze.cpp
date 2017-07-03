//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

//global! OK for learing
const int N_Size = 10;
int M, N;
int path[N_Size][N_Size];

//
int print(int arr[][N_Size]) {
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


bool printPath(char board[][N_Size], int x, int y) {
	if (x == M - 1 && y == N - 1) {
		path[x][y] = 1;
		print(path);
		path[x][y] = 0;
		return true;
	}

	if (x >= M) return false;	//out of the board

	if (y == N) {
		//can't move forward, but can move downwards!
		return printPath(board, x + 1, y);
	}


	if (board[x][y] == 'x')	return false;

	path[x][y] = 1;
	bool forward = printPath(board, x, y + 1);
	if (forward == true) return true;

	bool downward = printPath(board, x + 1, y);
	if (downward == true) return true;

	path[x][y] = 0;
	return false;




}

int main() {
	char board[][N_Size] = {
		".x.x....",
		".....x..",
		"x.x...x.",
		"........"
	};

	M = N = 8;

	printPath(board, 0, 0);

}