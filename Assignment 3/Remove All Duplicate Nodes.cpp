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

Node* removeDuplicates(Node* a){

    Node* current = a;
    Node* prev = new Node;
    prev->next = a;
    Node* nodestart = prev->next;
    while(current != NULL){
        while(current->next != NULL && prev->next->data == current->next->data){
            current = current->next;
        }
        if(prev->next == current){
            prev = prev->next;
        }
        else{
            prev->next = current->next;
        }
        current = current->next;
    }
    a = nodestart;
    return a;
}

int main(){
	SinglyLinkedList s1, res;
	s1.insertEnd(1);
    s1.insertEnd(2);
    s1.insertEnd(2);
    s1.insertEnd(4);
    s1.insertEnd(5);
    s1.insertEnd(5);
    s1.insertEnd(6);
    res.head = removeDuplicates(s1.head);
	res.printList();
	return 0;
}
