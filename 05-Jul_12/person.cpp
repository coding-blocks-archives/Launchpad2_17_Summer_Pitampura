//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <cstring>
#include <iostream>
using namespace std;

class Person{
public:
	char name[10];
	int priority;
	char phone[11];

	/*Person(){
		//default ctor
	}*/

	Person(char arr[], int p, char ph[]){
		strcpy(name, arr);
		priority = p;
		strcpy(phone, ph);
	}

	
};


int main(){
	Person P("sonia", 2, "1234567890");

	cout << P.name << " " << P.priority << " " << P.phone << endl;

}