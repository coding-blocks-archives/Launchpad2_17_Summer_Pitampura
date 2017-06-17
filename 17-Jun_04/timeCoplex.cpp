//Deepak Aggarwal, Coding Blocks
#include <iostream>
#include <ctime>
using namespace std;
int main(){
	time_t beg= time(0);

	for(int i = 0; i < (int)1e7; ++i){
		for(int j = 0; j < 1000; ++j){
			// something
		}
	}

	time_t stop = time(0);
	cout << (stop - beg);
}