template <typename T1>
class specialPair{
	T1 var1;
	T1 var2;
public:
	specialPair(T1 X, T1 Y){
		if(X > Y){
			var1 = X;
			var2 = Y;
		}
		else {
			var1 = Y;
			var2 = X;
		}
	}
};

class Customer{
	int cid;
public:
	bool operator>(const Customer& C) const {
		return id > C.id;
	}

}; 

int main(){
	Customer c1;
	Customer c2;
	specialPair<Customer> sc(c1, c2);
	c1 > c2;	//c1.opeator>(c2)
}