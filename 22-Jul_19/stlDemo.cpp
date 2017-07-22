#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool compareFun(int a, int b){
	return a > b;
}

class compare{
public:
	bool operator()(int a, int b){
		return a > b;
	}
};


int main(){
	// vector<int> v;

	// vector<char> vc(5, 'a');

	// // cout << v[0] << endl;
	// cout << vc[1] << endl;
	

	// priority_queue<int, vector<int> , compare> q;	//maxHeap of int

	// q.push(3);
	// q.push(9);
	// cout << q.top();

}