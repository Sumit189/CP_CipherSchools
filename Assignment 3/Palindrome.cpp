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
		return NULL;
	}
		Node *curr = a, *prev = NULL, *nxt = NULL;
		while(curr != NULL){
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		a = prev;
		return a;
}

bool compare(Node* f, Node* s){
	while(f!=NULL && s!=NULL){
		if(f->data != s->data){
			return false;
		}
		f=f->next;
		s=s->next;
	}
	return true;
}

bool isPalindrom(Node* head){
	SinglyLinkedList frst, second;
	Node* fast = head, *slow = head;
	int count1 = 0, count;
	while(fast != NULL && fast->next != NULL){
		fast=fast->next->next;
		frst.insertEnd(slow->data);
		slow = slow->next;
		count1++;
	}
	second.head = reverseLL(slow);
	return compare(frst.head,second.head);
}


int main(){
	SinglyLinkedList s1;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertEnd(2);
	s1.insertEnd(1);
	if(isPalindrom(s1.head)){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}
