#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(){
			Node(0);
		}
		Node(int data){
			this->data =  data;
			this->next = NULL;
		}
};
class SinglyLinkedList{
	public:
		Node* head;
		SinglyLinkedList(){
			this->head=NULL;
		}
		
		void insertBeg(int data){
			Node* newNode = new Node(data);
			if(head == NULL){
				head = newNode;
			}
			else{
				newNode->next = head;
				head = newNode;
			}
		}
		
		void insertEnd(int data){
			Node* newNode = new Node(data);
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
		
		void printList(){
			Node* ptr = head;
			while(ptr != NULL){
				cout<<ptr->data<<" ";
				ptr = ptr->next;
			}
		}
		
};

int getSize(Node *a){
	int count = 0;
	while(a != NULL){
		count++;
		a = a->next;
	}
	return count;
}

void intersection(Node* a, Node* b){
	if(a == NULL || b == NULL)
	cout<<"Nothing is common";
	
	while(a != NULL && b != NULL){
		if(a->data == b->data){
			cout<<a->data<<" ";
			a = a->next;
			b = b->next; 
		}
		else if(a->data < b->data){
			a = a->next;
		}
		else{
			b = b->next;
		}
	}
}

int main(){
	SinglyLinkedList s1, s2, res;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s2.insertEnd(2);
	s2.insertEnd(3);
	s2.insertEnd(4);
	intersection(s1.head, s2.head);
	return 0;
}
