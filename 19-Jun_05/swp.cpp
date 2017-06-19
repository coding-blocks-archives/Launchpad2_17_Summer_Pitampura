//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

void mySwap(int a, int b){
	cout << "\n----Inside mySwap----\n";
	cout << "Before swap \n";
	cout << a << " " << b << endl;

	int tmp = a;
	a = b;
	b = tmp;

	cout << "After Swap \n";
	cout << a << " " << b << endl;
}

void mySwap_ref(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	int x;
	int y;
	cout << "Inside Main\n";
	cin >> x >> y;
	mySwap_ref(x, y);
	cout << "Inside Main\n";
	cout << x << y;	
}