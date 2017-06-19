//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

bool isPrime(int num){
	// for(int div = 2; div < root(num); ++div)
	for(int div = 2; div * div <= num; ++div){
		if (num % div == 0){
			return false;
		}
	}
	return true;
}


int main(){
	int num;
	cin >> num;
	cout << isPrime(num);	
}