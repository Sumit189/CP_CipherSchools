#include<bits/stdc++.h>
using namespace std; 

class Node{
    public:
    int data;
    Node* next;

    Node(){
        Node(0);
    }

    Node(int data){
        this->data = data;
        this->next = NULL; 
    }
};


class Dequeue{
	public:
		Node* head;
		Dequeue(){
			this->head =  NULL;
		}
		
		void insertFront(int data){
			Node* newNode = new Node(data);
			if(head = NULL){
				head = newNode;
			}
			else{
				newNode->next = head;
				head = newNode;
			}
		}
		
		void insertLast(int data){
			Node* newNode = new Node(data);
			newNode->next = NULL;
			if(head == NULL){
				head = newNode;
			}
			else{
				Node* ptr = head;
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = newNode;
			}
		}
		
		void deleteFront(){
			if(head != NULL){
				Node *ptr = head->next;
				delete head;
				head = ptr;
			}
		}
		
		void deleteLast(){
			if(head != NULL){
				Node *ptr = head;
				while(ptr->next->next != NULL){
					ptr = ptr->next;
				}
				delete (ptr->next);
				ptr->next =  NULL;
			}
		}
		
		int getFront(){
			if(head == NULL)
			return -1;
			if(head == NULL)
			cout<<"NULL";
				return head->data;
		}
		
		int getRear(){
			if(head == NULL)
			return -1;
				Node* ptr = head;
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				return ptr->data;
			
		}
		
		void printQueue(){
				Node* ptr = head;
				while(ptr != NULL){
					cout<<ptr->data<<" ";
					ptr = ptr->next;
				}
		}
		
};

int main(){
    cout<<endl<<"\nQueue"<<endl;
	Dequeue q;
	q.insertFront(1);
	q.insertLast(2);
	q.insertLast(3);
	q.insertLast(4);
	q.insertLast(5);
	cout<<"Queue Elements: ";
	q.printQueue();

	cout<<endl<<"Get Front: "<<q.getFront()<<endl<<"Get Rear: "<<q.getRear()<<endl;
	cout<<"Delete From Last: ";
	q.deleteLast();
	q.printQueue();
	cout<<endl;
	cout<<"Delete From Front: ";
	q.deleteFront();
	q.printQueue();

    return 0;
}
