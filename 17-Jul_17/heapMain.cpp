//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com
#include <iostream>
#include "heap.h"
using namespace std;

int main(){

	heap H;
	H.push(100);
	H.push(-2);
	H.push(200);
	H.push(10);
	H.push(-17);

	while(H.empty() == false){
		cout << H.top() << " ";
		H.pop();
		
	}
			
}