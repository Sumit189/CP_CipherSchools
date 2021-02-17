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
		this->data = data;
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

Node* reverseLL(Node* a){
	if(a == NULL || a->next == NULL){
		cout<<"Empty List";
	}
	else{
		Node *curr = a, *prev = NULL, *nxt = NULL;
		while(curr != NULL){
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		
		}
		a = prev;
	}
	return a;
}

int main(){
	SinglyLinkedList s1;
	s1.insertEnd(10);
	s1.insertEnd(20);
	s1.insertEnd(30);
	
	s1.head=reverseLL(s1.head);
	s1.printList();
	return 0;
}
