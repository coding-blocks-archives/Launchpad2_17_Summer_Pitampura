//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	char c;
	cin.get(c);	//same as c = cin.get()

	int lines = 0, words = 0, characters = 0;
	bool insideWord = false;

	while(c != '$'){
		if (c == ' ' || c == '\n' || c == '\t'){
			if (insideWord == true){
				++words;
			} 
			insideWord = false;

			if (c == '\n'){
				++lines;
			}
		}
		else {
			insideWord = true;
		}
		++characters;
		c = cin.get();
	}
	if (insideWord == true) ++words;
	cout << "Words : " << words << endl;
	cout << "chars : " << characters << endl;
	cout << "lines : " << lines << endl;

}