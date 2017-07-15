#include "myqueue.h"
#include <iostream>
using namespace std;

int main(){
	Queue Q;
	Q.push(1);
	Q.push(2);

	cout << Q.getFront() << endl;
	Q.push(3);
	cout << Q.getFront() << endl;
	Q.pop();
	Q.pop();
	Q.pop();
	cout << Q.getFront();
	
}