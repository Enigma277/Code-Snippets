#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node *next;
};

class Queue{
private:
	node *head, *tail;
	int size;
public:
	Queue(){
		head=NULL;
		tail=NULL;
		size = 0; 
	}

	void push(int val){
		node *temp = new node;
		temp -> data = val;
		temp ->next = NULL;

		if(head == NULL){
			head = tail =temp;
		}else{
			tail->next = temp;
			tail = tail ->next; 
		}
		size++;

	}

	void pop(int index = 1){
		if(size == 0 ){
			cout<<"underflow\n";
			return;
		}
		node  *cur = head;

		head = cur ->next;
		free(cur);
		size--;
		return;
	}

	int get_size(){
		return size;
	}

	int front(){
		if(size == 0){
			cout<<"underflow\n ";
			return -1;
		}

		return head -> data; 
	}

	bool empty(){
		return size == 0;
	}

};

int main() {
 
}