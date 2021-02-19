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

int getSize(Node* a){
    int count = 0;
    while(a != NULL){
        a = a->next;
        count++;
    }
    return count;
}

Node* replaceKth(Node* a, int k){
    int size = getSize(a);
    if(a == NULL){
        return NULL;
    }
    if(size < k || 2*k == size){
        return NULL;
    }
    Node* from_start = new Node;
    Node* start_prev = new Node;
    start_prev->next = a;
    from_start = a;
    for(int i = 1; i <= k-1; i++){
        start_prev = from_start;
        from_start = from_start->next;    
    }
    Node* fromLast = new Node;
    fromLast->next = a;
    Node* last_prev = new Node;
    last_prev->next = a;

    for(int i=1; i <= size-k+1; i++){
        last_prev = fromLast;
        fromLast = fromLast->next;
    }

    Node* tempstart = start_prev->next;
    start_prev->next = fromLast;
    Node* temp = fromLast->next;
    fromLast->next = from_start->next;

    last_prev->next = tempstart;
    from_start->next = temp;
    if(getSize(a) == 1){
        a = from_start;
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
    s1.insertEnd(6);
    s1.insertEnd(7);
    s1.insertEnd(8);
    s1.insertEnd(9);
    s1.insertEnd(10);

    res.head = replaceKth(s1.head, 10);
     res.printList(); 
    

	return 0;
}
