#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class Doublylist{
    Node* head;
    Node* tail;
    public:
    Doublylist(){
    head=tail=NULL;
    }
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }else{
           newnode->next=head;
           head->prev=newnode;
           newnode=head;
        }
    }
    void push_back(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        return;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=NULL;
            tail=newnode;
        }
    }
    void pop_front(){
        if(head==NULL){
            head=tail;
            return;
        }
        Node* temp=head;
        temp->next=head;
        if(head!=NULL){
        head->prev=NULL;
    }
    temp->next=NULL;
        delete temp;

    }
    void cp(){
        if(head==NULL){
            return;
        }
            Node* temp=head->next;
            int ct=0;
            while(temp->next!=NULL){
                if((temp->data>temp->next->data && temp->data>temp->prev->data )|| (temp->data<temp->next->data && temp->data<temp->prev->data)){
                    ct++;
            }
            temp=temp->next;
            }
            cout<<ct<<endl;
 
    }
    
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
    void cycle(){
        
    }


};
int main(){
    Doublylist dll;
   // dll.push_front(3);
     dll.push_back(1);
     dll.push_back(2);
     dll.push_back(3);
     dll.push_back(3);
     dll.push_back(3);
     dll.push_back(5);
     dll.push_back(1);
     dll.push_back(3);
     dll.cp();

      dll.print();
      
}
