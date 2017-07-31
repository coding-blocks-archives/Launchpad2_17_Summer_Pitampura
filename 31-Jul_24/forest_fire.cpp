//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <queue>
using namespace std;

char forest[25][25];
bool visited[25][25];
int M, N;

bool isSafe(int i, int j){
	if (i >= 0 && i < M && j >= 0 && j < N && forest[i][j] == 'T' && !visited[i][j]){
		return true;
	}
	return false;

}

int bfs(int sr, int sc){
	queue<int> r;
	queue<int> c;

	r.push(sr);
	c.push(sc);
	visited[sr][sc] = true;

	r.push(-1);
	c.push(-1);

	int ans = 0;
	
	int rdir[] = {-1, -1, -1, 0, +1, +1, +1, 0};
	int cdir[] = {-1, 0, +1, +1, +1, 0, -1, -1};

	while(r.empty() == false){
		int ri = r.front();
		int ci = c.front();
		// cout << ri << " " << ci << endl;
		r.pop();
		c.pop();

		if (ri == -1){
			++ans;
			if (r.empty() == false){
				r.push(-1);
				c.push(-1);
			}
			continue;
		}

		for(int i = 0; i < 8; ++i){
			if (isSafe(ri + rdir[i], ci + cdir[i])){
				visited[ri + rdir[i]][ci + cdir[i]] = true;
				r.push(ri + rdir[i]);
				c.push(ci + cdir[i]);
			}
		}
	}
	return ans;
}


int main() {
	cin >> M >> N;
	int srcR, srcC;
	cin >> srcR >> srcC;
	--srcR; --srcC;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> forest[i][j];
		}
	}
	// cout << "Hi";
	int ans = bfs(srcR, srcC);
	cout << ans;

	return 0;

}