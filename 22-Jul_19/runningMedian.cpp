#include <iostream>
#include <queue>
using namespace std;

class compare{
public:
	bool operator()(const int& a, const int& b){
		return a > b;
	}
};

void printRunningMedian(){
	int x;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, compare> minHeap;

	while(true){
		cin >> x;
		if (x == -1) break;

		if (maxHeap.empty() || maxHeap.top() > x){
			maxHeap.push(x);
		}
		else {
			minHeap.push(x);
		}

		if (maxHeap.size() - minHeap.size() > 1){
			int ele = maxHeap.top();
			maxHeap.pop();
			minHeap.push(ele);
		}

		cout << maxHeap.top() << " ";
	}
}



int main(){
	printRunningMedian();
	return 0;
}