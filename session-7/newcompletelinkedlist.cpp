//Name: Aditya Dubey
//UID: 24BCS10457
#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node* link;
    
    node(int x){
        value=x;
        link=NULL;
    }
};

class linkedlist{
    node* start=NULL;
    
    public:
    void createlist(){
        node* node1=new node(10);
        start=node1;
        node* node2=new node(20);
        node1->link=node2;
        node* node3=new node(30);
        node2->link=node3;
    }
    
    void insertatbeg(int x){
        node* newnode=new node(x);
        newnode->link=start;
        start=newnode;
    }
    
    void insertatend(int x){
        node* newnode=new node(x);
        if (start==NULL){
            start=newnode;
        }
        else{
            node* temp=start;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link=newnode;
        }
    }
    void deleteatbeg(){
        if(start==NULL){
            cout<<"list is empty\n";
            return;
        }
        else{
            node* temp=start;
            start=start->link;
            delete temp;
        }
    }
    
    void deleteatend(){
        node* next=start;
        node* prev=start;
        if(start==NULL){
            cout<<"list is empty\n";
            return;
        }
        else if(start->link==NULL){
            start=NULL;
            delete next;
        }
        else{
            while(next->link!=NULL){
                next=next->link;
                if(prev->link->link!=NULL){
                    prev=prev->link;
                }
            }
            prev->link=NULL;
            delete next;
        }
    }
    
    void display(){
        node* temp=start;
        if(start==NULL){
            cout<<"empty list\n";
        }
        else{
            while(temp!=NULL){
                cout<<temp->value<<"    ";
                temp=temp->link;
            }
            cout<<"\n";
        }
    }
};

int main(){
    linkedlist a;
    a.createlist();
    a.display();
    a.insertatbeg(100);
    a.display();
    a.insertatend(200);
    a.display();
    a.deleteatend();
    a.display();
    a.deleteatbeg();
    a.display();
}