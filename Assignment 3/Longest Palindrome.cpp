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


int common(Node *a, Node *b) { 
    int count = 0; 
  	while(a != NULL && b != NULL){
        if (a->data == b->data) 
            ++count; 
        else
            break; 
    	a = a->next;
    	b = b->next;
	}
    return count; 
} 

int longestPalindrome(Node *head){ 
    int result = 0; 
    Node *prev = NULL, *curr = head; 
    while(curr) { 
        Node *next = curr->next; 
        curr->next = prev; 
        result = max(result, 2*common(prev, next)+1); 
        result = max(result, 2*common(curr, next)); 
        
        prev = curr; 
        curr = next; 
    } 
    return result; 
} 



int main(){
	SinglyLinkedList s1;
	s1.insertEnd(2);
	s1.insertEnd(4);
	s1.insertEnd(3);
	s1.insertEnd(4);
	s1.insertEnd(2);
	s1.insertEnd(15);
	int res = longestPalindrome(s1.head);
	cout<<res;
	return 0;
}
