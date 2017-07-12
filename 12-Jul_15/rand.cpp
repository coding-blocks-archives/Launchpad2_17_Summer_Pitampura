//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main(){
	srand(time(NULL));		//seeding of rand()
	int res = rand() % 100;
	cout << res;
}