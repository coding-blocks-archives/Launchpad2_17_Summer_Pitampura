//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "graph.h"
using namespace std;
int main(){
	Graph g(6);

	g.addEdge(1, 6, 1); //passport-->ticket
	g.addEdge(1, 4, 1);	//passport-->insurance
	g.addEdge(6, 2, 1);	//ticket-->visa
	g.addEdge(4, 2, 1);	//insurance-->visa
	g.addEdge(2, 3, 1); //visa-->gifts
	g.addEdge(2, 5, 1);	//visa-->forex

	vector<int> ans = g.topologicalSort();

	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i] << "--";
	}
}