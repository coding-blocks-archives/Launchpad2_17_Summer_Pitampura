//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <cstring>
using namespace std;

class Student{
	char * name;
	//Intention : char * name = new char[n];
	int rollno;
public:
	//Parameterised Constructor
	Student(char s[], int r){
		rollno = r;
		int n = strlen(s);
		name = new char[n];
		//dynamic allocation
		strcpy(name , s);
	}

	//copy ctor
	//default ctor copies all DATA members by VALUE
	Student(const Student& X){
		int n = strlen(X.name);
		name = new char[n];
		//If not done, name would point to X.name which is wrong contextually
		strcpy(name, X.name);
		rollno = X.rollno;
	}

	void print(){
		cout << name << rollno << endl;
	}

	void deleteStud(){
		delete name;
	}

	char * getStudent(){
		return name;
	}

	~Student(){
		// cout << "Inside destructor of " << name << endl;
		delete [] name;	//free memory allocated by new
		//doesn't follow scope rules
	}
};

char* foo(){
	Student S("abc", 11);
	// S.print();
	// char * tmp = S.getStudent();
	// return tmp;
}


int main(){
	char * x = foo();
	cout << x << endl;

}