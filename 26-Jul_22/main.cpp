//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "graph.h"
using namespace std;
int main(){
	// int n;
	// cin >> n;
	Graph g(5);

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);

	g.addEdge(2,5);

	g.addEdge(3,4);
	g.addEdge(3,5);

	g.addEdge(4,5);

	// g.printGraph();

	// g.dfs(3);

	// int ans = g.connectedComponents();
	// cout << ans;

	int ans = g.shortestDistance(1, 2);
	cout << ans;

}