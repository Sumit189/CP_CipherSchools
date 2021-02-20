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

Node* reverseLL(Node *a, int K){
	if(a == NULL || a->next == NULL)
	return NULL;
	
	int k = 0;
	Node *curr = a, *prev = NULL, *next = NULL;
	while(curr != NULL && k<K){
		k++;
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	a = prev;
	return a;
}

Node* reverseK(Node* a, int k){
	if(a == NULL)
	return NULL;
	if(k > getSize(a)){
		return NULL;
	}
	int c_ = 1;
	Node *ptr = a;
	while(1){
		if(c_ == k){
			break;
		}
		c_++;
		ptr = ptr->next;
	}
	Node *firsthalf = new Node(), *sh = ptr->next;
	firsthalf = reverseLL(a, k);
	SinglyLinkedList res;
	while(firsthalf!=NULL){
		res.insertEnd(firsthalf->data);
		firsthalf = firsthalf->next;
	}
	while(sh!=NULL){
		res.insertEnd(sh->data);
		sh = sh->next;
	}

	return res.head;
}
int main(){
	SinglyLinkedList s1,s2;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertEnd(4);
	s1.insertEnd(5);
	s1.insertEnd(6);
	s1.insertEnd(7);
	s2.head = reverseK(s1.head, 3);
	s2.printList();
	return 0;
}
