//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "graph.h"
using namespace std;

int main() {
	Graph g(36);

	int snakeLadder[37] = {0};

	snakeLadder[2] 		= 		15;
	snakeLadder[5]		= 		7;
	snakeLadder[9] 		= 		27;
	snakeLadder[17]		= 		4;
	snakeLadder[18]		= 		29;
	snakeLadder[20]		= 		6;
	snakeLadder[24]		= 		16;
	snakeLadder[25]		= 		35;
	snakeLadder[32]		= 		30;
	snakeLadder[34]		= 		12;


	for (int box = 1; box <= 36; ++box) {
		if (snakeLadder[box] != 0) continue;	//either snake/ladder box doesn't exist
		for (int dice = 1; dice <= 6; ++dice) {
			int dest = box + dice;
			if (snakeLadder[dest] != 0) dest = snakeLadder[dest];	//dest doesnt't exist...snake or ladder
			if (dest <= 36) {
				g.addEdge(box, dest, true);
			}
		}
	}

	int ans = g.shortestDistance(1, 30);
	cout << ans;

}