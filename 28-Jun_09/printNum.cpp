//Deepak Aggarwal, Coding Blocks

#include <iostream>
using namespace std;

const char corresponsdingDig[][10] = {
	"zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine"
};

char* digToStr(int dig){
	char *ans = NULL;
	switch(dig){
		case 0:	ans = "zero"; break;
		case 1:	ans = "one"; break;
		case 2: ans = "two"; break;
		case 3: ans = "three"; break;
		case 4: ans = "four"; break;
		case 5: return "five";
		case 6: return "six";
		case 7: return "seven";
		case 8: return "eight";
		case 9: return "nine";
		default : return "emptiness";
	}
	return ans;
}

void printNum(int num){
	if (num == 0){
		return;
	}

	// int smallerNum = num / 10;
	// printNum(smallerNum);
	printNum(num / 10);

	
	int dig = num % 10;
	/*if (dig == 0)	cout << "zero";
	else if (dig == 1) 	cout << "one";
	else if (dig == 2) 	cout << "two";
	else if (dig == 3) 	cout << "three";
	else if (dig == 4) 	cout << "four";
	else if (dig == 5) 	cout << "five";
	else if (dig == 6) 	cout << "six";
	else if (dig == 7) 	cout << "seven";
	else if (dig == 8) 	cout << "eight";
	else if (dig == 9) 	cout << "nine";*/

	// char * corresponsdingStr = digToStr(dig);
	// cout << corresponsdingStr;
	cout << corresponsdingDig[dig];

	cout << " ";
}



int main(){
	int num;
	cin >> num;
	// cout << digToStr(num);

	printNum(num);
	
}