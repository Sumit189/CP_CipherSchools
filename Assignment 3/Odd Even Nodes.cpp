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

Node* oddEvenNodes(Node* a){
    if(a == NULL)
    return NULL;

    Node* odd = a;
    Node* even = a->next;
    Node* evenstart = even;
    while(1){
        if(odd == NULL || even == NULL || even->next==NULL){
            odd->next = evenstart; 
            break;
        }
        odd->next = even->next;
        odd = even->next;

        if(odd->next == NULL){
            even->next = NULL;
            odd->next = evenstart;
            break;
        }
        even->next =  odd->next;
        even = odd->next;
    }
    return a;
}
int main(){
	SinglyLinkedList s1, res;
	s1.insertEnd(1);
    s1.insertEnd(2);
    s1.insertEnd(3);
    s1.insertEnd(4);
    s1.insertEnd(5);
    res.head = oddEvenNodes(s1.head);
	res.printList();
	return 0;
}
