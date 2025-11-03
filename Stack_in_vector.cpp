#include<bits/stdc++.h>
using namespace std;
class Stack{
	//implementing stack as a vector
	vector<int> v;
	public: 
	void push(int val){
		v.push_back(val);

	}
	void pop(){
    v.pop_back();
	}
	int top(){
		return v[v.size()-1];

	}
	bool empty(){
		return v.size()==0;

	}


};

int main(){
	
	Stack s;
	s.push(10);
	s.push(12);
	s.push(30);
	s.push(40);
	while(!s.empty()){
		cout<<s.top()<<" "; //40 30 12 10
		s.pop();
	}
	cout<<endl;


}