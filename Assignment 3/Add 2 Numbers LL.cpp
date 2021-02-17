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
		return a;
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

void AddTwoNum(Node* a, Node* b){
	a = reverseLL(a);
	b = reverseLL(b);
	
	string frst="";
	
	while(a != NULL){
		frst+=to_string(a->data);
		a=a->next;
	}
	

	string second="";
	while(b != NULL){
		second+=to_string(b->data);
		b=b->next;
	}

	
	long num1 = stoi(frst);
	long num2 = stoi(second);
	long sum = num1+num2;
	
	string res_sum=to_string(sum);
	
	SinglyLinkedList res;
	int len = 0;
	if (sum>0)
		len = (int)log10(sum)+1;
		
	if(len == 0)
		res.insertEnd(res_sum[0]-'0');
	else
		for(int i = 0; i < len ; i++){
			res.insertEnd(res_sum[i]-'0);
		}
	
		
	res.head = reverseLL(res.head);
	res.printList();
}

int main(){
	SinglyLinkedList s1,s2;
	s1.insertEnd(7);
	s1.insertEnd(5);
	s1.insertEnd(9);
	s1.insertEnd(4);
	s1.insertEnd(6);
	s2.insertEnd(8);
	s2.insertEnd(4);
	AddTwoNum(s1.head,s2.head);
	return 0;
}
