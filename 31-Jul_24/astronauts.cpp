//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph{
	list<int> adjList[(int)1e5];
	int nV;
public:
	Graph(int n){
		nV = n;
	}

	void addEdge(int src, int dest){
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	int dfs(int src, vector<bool>& visited){
		visited[src] = true;
		int cnt = 1;

		for(list<int>::iterator it = adjList[src].begin(); 
			it != adjList[src].end(); ++it){
			if(visited[*it] == false){
				cnt += dfs(*it, visited);
			}
		}
		return cnt;
	}

	vector<int> connectedComp(){
		vector<bool> visited(nV, false);
		vector<int> cnt(nV); 
		int k  = 0;

		for(int i = 0; i < nV; ++i){
			if (visited[i] == false){
				cnt[k] = dfs(i, visited);
				++k;
			}
		}
		return cnt;
	}
};

typedef long long int ll;

ll totalWays(const vector<int>& v, ll N){
	ll ans = 0;
	ans = N * (N - 1) / 2;

	for(int i = 0; i < v.size(); ++i){
		ans -= v[i] * (v[i] - 1) / 2;
	}

	return ans;
}

int main(){
	int N, P;
	cin >> N >> P;
	Graph g(N);

	for(int i = 0; i < P; ++i){
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}

	vector<int> v = g.connectedComp();
	ll ans = totalWays(v, N);
	cout << ans;
	return 0;

	con
}