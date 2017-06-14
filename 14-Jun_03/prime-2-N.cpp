//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;

	for (int curNum = 2; curNum <= N; ++curNum){	//loop1
		//if curNum is prime --> print it
		bool isPrime = true;
		int div = 2;
		while (div < curNum){		//loop2
			if (curNum % div == 0){
				//div is a factor of curNum
				isPrime = false;
				break;
			}
			++div;
		}
		if (isPrime == true){
			cout << curNum << " ";
		}
	}	
}