//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

//function definition
void fahrToCel(){
	for(int fah = 0; fah <= 300; fah = fah + 20){
		//print cel 
		double celEquv = (5.0 / 9) * (fah - 32);
		cout <<fah << "\t" << celEquv << "\n";
	}
}

//function definition with formal arguments
void fahrToCel2(int beg, int en, int step){
	for(int fah = beg; fah <= en; fah = fah + step){
		//print cel 
		double celEquv = (5.0 / 9) * (fah - 32);
		cout <<fah << "\t" << celEquv << "\n";
	}
}



int main(){
	// fahrToCel();	//calling
	int initial, final, step;
	cin >> initial >> final >> step;
	fahrToCel2(initial, final, step);
	
	cout << "New initial\n";
	cin >> initial >> final >> step;
	fahrToCel2(initial, final, step);


}