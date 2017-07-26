//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "weightedGraph.h"
using namespace std;
int main() {
	Graph g(7);

	g.addEdge(1, 2, 10);
	g.addEdge(1, 3, 80);
	g.addEdge(2, 5, 20);
	g.addEdge(2, 3, 6);
	g.addEdge(5, 6, 50);
	g.addEdge(5, 7, 10);
	g.addEdge(7, 6, 5);
	g.addEdge(3, 4, 70);

	int sol = g.dijikstra(1,6);
	cout << sol;

}