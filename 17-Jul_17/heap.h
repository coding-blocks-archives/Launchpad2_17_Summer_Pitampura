#ifndef _HEAP__H
#define _HEAP__H

#include <iostream>
#include <vector>
using namespace std;

class heap {
	vector<int> v;
	int sze;

	int parent(int i) {return i / 2;}
	int left(int i) {return i * 2;}
	int right(int i) {return 2 * i  + 1;}

	void heapify(int idx){
		if (idx <= 0 || idx >= sze) return;

		int minPos = idx;
		if (left(idx) <= sze && v[left(idx)] < v[minPos]){
			minPos = left(idx);
		}

		if (right(idx) <= sze && v[right(idx)] < v[minPos]){
			minPos  = right(idx);
		}

		if (minPos == idx) return;
		swap(v[minPos], v[idx]);
		heapify(minPos);
	}

public:
	heap() {
		// v[0] = -1;
		v.push_back(-1);
		sze = 0;
	}

	int size() {
		return sze;
	}

	bool empty() {
		return sze == 0;
	}

	void push(int x) {
		//insertion
		v.push_back(x);
		++sze;
		//heapify type

		int idx = sze;
		while(idx > 1 && v[parent(idx)] > v[idx]){
			swap(v[parent(idx)], v[idx]);
			idx = parent(idx);
		}
	}

	int top(){
		//get MIN
		if (!empty()) return v[1];
		return -1;
	}

	void pop(){
		//deletion
		if (empty()) return;

		swap(v[1], v[sze]);
		--sze;

		heapify(1);
	}
};

#endif