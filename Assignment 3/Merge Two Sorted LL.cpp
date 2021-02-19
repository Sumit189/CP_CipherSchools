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

Node* merge_sorted(Node* a, Node* b){
    if(a == NULL)
    return b;
    if(b == NULL)
    return a;

    if(a->data < b->data){
        a->next = merge_sorted(a->next, b);
        return a;
    }
    else{
        b->next = merge_sorted(a, b->next);
        return b; 
    }
    return a;
}

int main(){
	SinglyLinkedList s1, s2, res;
	s1.insertEnd(1);
    s1.insertEnd(2);
    s1.insertEnd(3);
    s1.insertEnd(4);
    s1.insertEnd(5);
    s2.insertEnd(6);
    s2.insertEnd(7);
    s2.insertEnd(8);
    s2.insertEnd(9);
    s2.insertEnd(10);

    res.head = merge_sorted(s1.head, s2.head);
	res.printList(); 
    

	return 0;
}
