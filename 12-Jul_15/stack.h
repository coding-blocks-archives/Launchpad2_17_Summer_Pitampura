#ifndef STACK_H_
#define STACK_H_

template <typename T>
class Stack{
private:
	T * arr;
	int top_i;	//top_index
public:
	Stack(){
		arr = new T[100];		//max size
		top_i = -1;
	}

	~Stack(){
		delete [] arr;
	}

	bool empty(){
		return top_i == -1;
	}

	int size(){
		return top_i + 1;
	}

	void push(T x){
		if (top_i < 100){
			++top_i;
			arr[top_i] = x;
		}
	}

	void pop(){
		if (empty()) return;
		--top_i;
	}

	T top(){
		if (!empty()){
			return arr[top_i];
		}
		return -1;
	}
};

#endif