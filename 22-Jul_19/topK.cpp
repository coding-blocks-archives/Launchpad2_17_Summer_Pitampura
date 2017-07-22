#include <iostream>
#include <queue>
using namespace std;

class comparator{
	//this DEFINES the priority
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

void printBestK(int arr[], int n, int k){
	//I want a minHeap
	// priority_queue<int> pq;	//maxHeap

	priority_queue<int, vector<int>, comparator> minHeap;

	//push 1st k elements
	int i = 0; 
	while(i < k){
		minHeap.push(arr[i]);
		++i;
	}

	//push 1 and pop 1
	//element popped is the smallest
	//I need the last K elements eligible for popping
	while(i < n){
		minHeap.push(arr[i]);
		minHeap.pop();
		++i;
	}

	while(!minHeap.empty()){
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
}




int main(){
	int arr[10];
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	printBestK(arr, n, k);
}