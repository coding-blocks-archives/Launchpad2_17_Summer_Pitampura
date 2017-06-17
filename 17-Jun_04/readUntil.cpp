//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;
int main(){
	char c = '\0';
	int n = 0;

	while(true){
		cin >> c;
		if (c == '$'){
			break;
		}
		++n;
		cout << c;
	}	

	cout << endl;
	cout << "No of chars read before $ " << n << endl;	
}