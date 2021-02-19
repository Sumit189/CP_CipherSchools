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

Node* alternate_merge(Node* first , Node* second){
	if(first == NULL)
	return second;
	
	if(second == NULL)
	return first;

	Node* head = first;
	Node* temp;
 	while(second){
	    temp = first->next;
	    first = first->next = second;
	    second = temp;
    }
	
	return head;
}

Node* reorder(Node* a){
	if(a == NULL || a->next == NULL){
		return a;
	}
	Node *slow = a, *fast = a->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	fast = slow->next;
	slow->next = NULL;
	
	fast = reverseLL(fast);
	slow = a;
	return alternate_merge(slow,fast); 
}


int main(){
	SinglyLinkedList s1, res;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertEnd(4);
	s1.insertEnd(5);
	res.head = reorder(s1.head);
	res.printList();
	return 0;
}
