//Deepak Aggarwal, Coding Blocks
#include <iostream>
using namespace std;
int main(){
	char c;
	// cin >> c;
	c = cin.get();	//reads one char
	int digit = 0;
	int alpha = 0;
	int space = 0;
	int others = 0;
	// others = 0;

	while (c != '$'){
		//if c is digit
		if (c >= '0' && c <= '9'){
			++digit;
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
			++alpha;
		}
		else if (c == ' ' || c == '\n' || c == '\t'){
			++space;
		}
		else {
			++others;
		}
		// cin >> c;
		c = cin.get();
	}	
	cout << "Alphabet : " << alpha << endl;
	cout << "digit : " << digit << endl;
	cout << "space : " << space << endl;
	cout << "others : " << others << endl;
}