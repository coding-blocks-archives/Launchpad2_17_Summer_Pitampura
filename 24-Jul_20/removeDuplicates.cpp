#include <iostream>
#include <map>
#include <set>
using namespace std;

//TODO 
//use map<int, bool> and inplace algo

void removeDuplicates(int arr[], int& n){
	// map<int, int> m;
	set<int> m;

	//building map
	for(int i = 0; i < n; ++i){
		int cur = arr[i];
		// m[cur] = cur;
		m.insert(cur);
	}

	int i  = 0;
	// for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
	for(set<int>::iterator it = m.begin(); it != m.end(); ++it){
		// arr[i] = it->second;
		arr[i] = *it;
		++i;
	}
	n = i;
	// delete ans;
}


int main(){
	//remove duplicates
	int arr[10];
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	removeDuplicates(arr, n);

	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
}