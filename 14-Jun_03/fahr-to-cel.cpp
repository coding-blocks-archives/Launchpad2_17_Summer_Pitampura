#include <iostream>
using namespace std;

int main(){
	//read 3 val-step, init, fina
	int step, init, final;
	// cin >> step;
	// cin >> init;
	// cin >> final;
	cin >> step >> init >> final;
	while(init <= final){
		//do something
		// int cel = 5.0 / 9 * (init - 32);
		double cel = 5.0 / 9 * (init - 32);	//to get decimal part also
		cout << init << "\t" << cel << "\n"; 
		init = init + step;
	}
}