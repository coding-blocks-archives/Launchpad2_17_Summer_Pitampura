#include <iostream>
#include <map>
#include <utility>
using namespace std;

pair<int, int> findX(int arr[], int n, int x){
	//lets build a hashmap/map

	map<int, bool> m;
	//filling the map
	for(int i = 0; i < n; ++i){
		// m.insert(arr[i], true);	WRONG!!!
		// pair<int, bool> p(arr[i], true);
		// m.insert(p);	//change
		// m[arr[i]] = true;
		int a = arr[i];
		m[a] = true;

	}

	//Now lets start the work!
	pair<int, int> ans(-1, -1);	//default
	for(int i = 0; i < n; ++i){
		int b = x - arr[i];
		// if (m[b] == true){	this inserts an element

		map<int, bool>::iterator it;
		it = m.find(b);

		if (it != m.end()){
			ans.first = arr[i];
			ans.second = b;
			break;
		}
	}

	return ans;



}

int main(){
	int arr[10];
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	int x;
	cin >> x;

	pair<int, int> sumToX = findX(arr, n, x);

	cout << sumToX.first << " " << sumToX.second << endl;
}