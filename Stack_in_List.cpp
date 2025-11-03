#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}
};

class List{
public:
	Node* head;
	Node* tail;
	List(){
		head=tail=NULL;
	}
	void push_front(int val){
		Node* newNode=new Node(val);
		if(head==NULL && tail==NULL){
			head=tail=newNode;
			return;
		}else{
			newNode->next=head;
			head=newNode;
		}



	}
	void pop_front(){
		if(head==NULL && tail==NULL){
				return;
			}
			else{
				Node* temp=head;
				head=head->next;
				delete temp;
			}
	}
	int front(){
		return head->data;
	}
	int size(){
		Node* temp=head;
		int ct=0;
		if(head==NULL && tail==NULL){
			return 0;
		}else{
			while(temp!=NULL){
				temp=temp->next;
				ct++;
			}
			return ct;
		}

	}
	void print(){
		Node* temp=head;
		while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
		}
		cout<<endl;

	}
};
class Stack{
	List ll;
public:
	void push(int val){
     ll.push_front(val);
	}
	void pop(){
		ll.pop_front();

	}
	int top(){
		return ll.front();

	}
	bool empty(){
		return ll.size()==0;
	}
};
int main(){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
     cout<<endl;
}