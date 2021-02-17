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

Node* reverseLLGroup(Node* a, int k){
	if(a == NULL || a->next == NULL){
		return NULL;
	}
		int K=0;
		Node *curr = a, *prev = NULL, *nxt = NULL;
		while(curr != NULL && K<k+1){
			K++;
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		if(nxt!=NULL){
			a->next=reverseLLGroup(nxt,K);
		}
		return prev;
}



int main(){
	SinglyLinkedList s1,s2;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertEnd(4);
	s1.insertEnd(5);
	
	s2.head=reverseLLGroup(s1.head, 2);
	s2.printList();
	return 0;
}
