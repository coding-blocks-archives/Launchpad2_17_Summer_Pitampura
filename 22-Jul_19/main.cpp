#include "hashmap.h"
#include <iostream>
using namespace std;

int main(){
	HashMap H;

	string s1 = "abc";
	string s2 = "def";

	H.insert(s1, 123);
	H.insert(s2, 567);

	int val  = H.find("def");
	cout << val << endl;

	return 0;
}