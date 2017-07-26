//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include <utility>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

class Graph{
	list<ii>* adjList;
	typedef list<ii>::iterator lit;
	int nV;

	class comp{
	public:
		bool operator()(const ii& A, const ii& B){
			return A.second > B.second;	//wt(A) < wt(Bs)
		}
	};
public:
	Graph(int n){
		nV = n;
		adjList = new list<ii>[nV + 1];
	}

	addEdge(int src, int dest, int wt){
		adjList[src].push_back(make_pair(dest, wt));
	}

	int dijikstra(int src, int dest){
		priority_queue<ii, vector<ii>, comp> pq;
		int * dist = new int[nV + 1];
		
		const int inf = 10000000;
		fill(dist, dist + nV + 1, inf);

		dist[src] = 0;
		pq.push(make_pair(src, 0));

		while(pq.empty() == false){
			ii cur = pq.top();
			pq.pop();
			int curVer = cur.first;
			int curWt = cur.second;

			if (dist[curVer] < curWt) continue;

			dist[curVer] = curWt;

			for(lit it = adjList[curVer].begin(); it != adjList[curVer].end(); ++it){
				ii n = *it;
				int wtFrmSrc = dist[curVer] + n.second;
				if (wtFrmSrc > dist[n.first]) continue;

				pq.push(make_pair(n.first, wtFrmSrc));
			}
		}
		int ans = dist[dest];
		delete [] dist;
		return ans;

	}
};