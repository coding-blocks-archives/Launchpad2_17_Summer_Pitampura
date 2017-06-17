//Deepak Aggarwal, Coding Blocks

#include <iostream>
#include <ctime>
using namespace std;
int main(){
	// clock_t beg = clock();
	time_t beg = time(0);
	for(int i = 0; i < (int)1e8; ++i) for(int j = 0; j < (int)10; ++j);
	// clock_t end = clock();
	time_t end = time(0);
cout << ctime(&end);
	// cout << difftime(end, beg);
	cout << end - beg;
	
}
