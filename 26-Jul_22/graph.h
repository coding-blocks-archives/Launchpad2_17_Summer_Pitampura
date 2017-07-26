#ifndef _GRAPH_H
#define _GRAPH_H

#include <list>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
	typedef list<int>::iterator lit;
	list<int> * adjList;
	int nV;

	void dfs_2(int src, bool visited[]) {
		// static bool* visited = new bool[nV + 1]{0};
		// static vector<bool> visited(100, false);

		visited[src] = true;
		cout << src << " ";

		//for all neighbours
		for (lit it = adjList[src].begin(); it != adjList[src].end(); ++it) {
			int curVer = *it;
			if (visited[curVer] == false) {
				dfs_2(curVer, visited);
			}
		}
	}
public:
	Graph(int n) {
		nV = n;
		adjList = new list<int>[nV + 1];
	}

	void addEdge(int v1, int v2, bool isDir = false) {
		adjList[v1].push_back(v2);
		if (isDir == false) adjList[v2].push_back(v1);
	}

	void printGraph() {
		for (int i = 1; i <= nV; ++i) {
			//print list corresponding to the vertex i
			cout << i << ": ";	//print vertex
			const list<int>& l = adjList[i];	//ref prevents copying
			for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
				cout << *it << "-->";
			}
			cout << endl;
		}
	}


	void dfs(int src) {
		bool * visited = new bool[nV + 1];
		for (int i = 1; i <= nV; ++i) {
			visited[i] = false;
		}

		dfs_2(src, visited);
		delete [] visited;
	}

	int connectedComponents() {
		bool * visited = new bool[nV + 1];
		for (int i = 0; i <= nV; ++i) { visited[i] = false; }
		int  cnt = 0;

		for (int ver = 1; ver <= nV; ++ver) {
			if (visited[ver] == false) {
				dfs_2(ver, visited);
				cout << endl;
				++cnt;
			}
		}
		delete [] visited;
		return cnt;
	}


	~Graph() {
		// cout << "Dtor called\n";
		delete [] adjList;
	}

	//26-Jul
	void bfs(int src) {
		bool * visited  = new bool[nV + 1];
		for (int i = 1; i <= nV; ++i) {
			visited[i] = false;
		}

		queue<int> q;
		q.push(src);
		visited[src] = true;

		while (q.empty() == false) {
			int curVer = q.front();
			q.pop();
			cout << curVer << " ";

			//push unvisited neigbours
			for (lit it = adjList[curVer].begin(); it != adjList[curVer].end(); ++it) {
				int curNeighbor = *it;
				if (visited[curNeighbor] == false) {
					visited[curNeighbor] = true;
					q.push(curNeighbor);
				}
			}
		}
	}

	int shortestDistance(int src, int dest) {
		int* dist = new int[nV + 1];
		bool *visited = new bool[nV + 1];
		int* parent = new int[nV + 1];

		//setting the initials
		fill(dist, dist + nV + 1, 0);
		fill(visited, visited + nV + 1, false);

		queue<int> q;
		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		parent[src] = src;

		while (q.empty() == false) {
			int curVer = q.front();
			q.pop();

			for (lit it = adjList[curVer].begin(); it != adjList[curVer].end(); ++it) {
				int curNeighbor = *it;
				if (visited[curNeighbor] == false) {
					visited[curNeighbor] = true;
					dist[curNeighbor] = 1 + dist[curVer];	//setting the distance
					parent[curNeighbor] = curVer;	//parent of the neighbor
					q.push(curNeighbor);
				}
			}
		}

		int ans = dist[dest];
		delete [] visited;
		delete [] dist;

		int x = dest;
		while(x != src){
			cout << x << "<--";
			x = parent[x];
		}
		cout << x;
		cout << endl;
		delete [] parent;
		
		return ans;
	}

	vector<int> topologicalSort(){
		vector<int> ans;

		int * inDegree = new int[nV + 1];
		fill(inDegree, inDegree + nV + 1, 0);

		for(int v = 1; v <= nV; ++v){
			//for all neighbours, inc req by 1
			for(lit n = adjList[v].begin(); n != adjList[v].end(); ++n){
				++inDegree[*n];
			}
		}

		queue<int> q;
		for(int i = 1; i <= nV; ++i){
			if (inDegree[i] == 0){
				q.push(i);
			}
		}

		while(q.empty() == false){
			int v = q.front();
			q.pop();
			ans.push_back(v);	//req fulfilled

			//dec indegree of a;ll neighbors
			for(lit it = adjList[v].begin(); it != adjList[v].end(); ++it){
				int neighbor = *it;
				--inDegree[neighbor];
				if (inDegree[neighbor] == 0){
					q.push(neighbor);
				}
			}
		}

		delete [] inDegree;
		return ans;

	}

};
#endif