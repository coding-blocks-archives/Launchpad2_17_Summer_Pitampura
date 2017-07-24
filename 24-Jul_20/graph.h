#ifndef _GRAPH_H
#define _GRAPH_H

#include <list>
#include <iostream>
#include <vector>
using namespace std;

class Graph{
	typedef list<int>::iterator lit;
	list<int> * adjList;
	int nV;
public:
	Graph(int n){
		nV = n;
		adjList = new list<int>[nV + 1];
	}

	void addEdge(int v1, int v2){
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}

	void printGraph(){
		for(int i = 1; i <= nV; ++i){
			//print list corresponding to the vertex i
			cout << i << ": ";	//print vertex
			const list<int>& l = adjList[i];	//ref prevents copying
			for(list<int>::const_iterator it = l.begin(); it != l.end(); ++it){
				cout << *it << "-->";
			}
			cout << endl;
		}
	}


	// vector<bool> visited;
	
	void dfs(int src){
		static bool* visited = new bool[nV + 1]{0};
		visited[src] = true;
		cout << src << " ";

		//for all neighbours
		for(lit it = adjList[src].begin(); it != adjList[src].end(); ++it){
			int curVer = *it;
			if (visited[curVer] == false){
				dfs(curVer);
			}
		}
	}


	~Graph(){
		cout << "Dtor called\n";
		delete [] adjList;
	}
};
#endif