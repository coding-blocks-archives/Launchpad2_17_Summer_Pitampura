//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;
int main(){
	int north = 0, east = 0, west = 0, south = 0;
	char c;
	cin.get(c);

	while(c != '$'){
		if (c == 'N')	++north;
		else if (c == 'S')	++south;
		else if (c == 'E') 	++east;
		else if (c == 'W')	++west;	
		cin.get(c);
	}	

	int netVert = north - south;
	int netHor = east - west;

	char horChar, verChar;
	if (netVert > 0) verChar = 'N';
	else verChar = 'S';

	if (netHor > 0) horChar = 'E';
	else horChar = 'W';

	while(netHor > 0){
		cout << horChar;
		--netHor;
	}

	while(netVert > 0){
		cout << verChar;
		--netVert;
	}

	while(netVert < 0){
		cout << verChar;
		++netVert;
	}

	while(netHor < 0){
		cout << horChar;
		++netHor;
	}

}