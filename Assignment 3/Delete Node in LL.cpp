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


Node* delNode(Node* a, int k){
	if(a == NULL)
	return NULL;
	
	if(getSize(a) < k){
		return NULL;
	}	
	Node* ptr = a;
	Node* h = ptr;
	int count = 0;
	while(ptr != NULL){
		count++;
		if(count == k-1 && ptr->next->next != NULL){
			ptr->next = ptr->next->next;
		}
		ptr = ptr->next;
	}
	return h;
}


int main(){
	SinglyLinkedList s1, res;
	s1.insertEnd(1);
	s1.insertEnd(2);
	s1.insertEnd(3);
	s1.insertEnd(4);
	res.head = delNode(s1.head, 2);
	res.printList();
	return 0;
}
