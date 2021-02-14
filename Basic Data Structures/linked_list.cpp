#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node *next;
};

class linked_list{
private:
	node *head, *tail;
	int size;
public:
	linked_list(){
		head=NULL;
		tail=NULL;
		size = 0; 
	}

	void print(){
		node *temp = head;
		while(temp != NULL){
			cout<< temp->data;
			if(temp -> next == NULL){
				cout<<endl;
			}else{
				cout<<" --> ";
			}
			temp = temp -> next;
		}
	}

	void add_at_back(int val){
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

	void add_at_front(int val){
		node *temp = new node;
		temp ->data = val;
		temp ->next = NULL;

		if(head == NULL){
			head = tail = temp;
		}else{
			temp -> next = head;
			head = temp;
		}
		size++;
	}

	void add_at_index(int index, int val){

		if(index > size){
			cout<<"Not possible to insert at this position\n";
			return;
		}

		if(index == 0){
			add_at_front(val);
		}else if(index == size){
			add_at_back(val);
		}else {
			node *temp = head;
			for(int i=0;i<index - 1; i++, temp = temp->next);	
			
			node *new_node = new node;
			new_node -> data = val;
			new_node -> next = temp->next;
			temp ->next = new_node;
			size++;
		}

	}

	void print_kth_element(int index){
		if(index > size || index < 1){
			cout<<"index out of bound\n";
			return;
		}
		node *temp = head;
		for(int i=0;i<index -1 ;i++,temp = temp -> next);
		cout<< temp -> data<<endl;
	}

	void delete_kth_element(int index){
		if(index > size || index < 1){
			cout<<"index out of bound\n";
			return;
		}
		node *prev, *cur = head;

		if(index == 1){
			head = cur ->next;
			free(cur);
			size--;
			return;
		}

		for(int i=1;i<index;i++){
			prev= cur;
			cur = cur -> next;
		}
		prev ->next = cur->next;
		free(cur);
		size--;
		if(index==size){
			tail=prev;
		}
	}


	void reverse(){
		node *prev = NULL, *current = head;
		while(current!=NULL){
			node *temp = current ->next;
			current ->next = prev;
			prev = current;
			current = temp; 
		}
		swap(head, tail);
	}

	int get_size(){
		return size;
	}

	node * get_head (){
		return head;
	}

	void merge(node *b_head){
		if(head == NULL){
			head = b_head;
			return;
		}
		if(b_head == NULL){
			return;
		}

		node *temp_head, *temp_tail;

		if(head -> data <= b_head->data){
			temp_head = head;
			temp_tail = head;
			head = head->next;
		}else {
			temp_head = b_head;
			temp_tail = b_head;
			b_head = b_head ->next;
		}


		while(head != NULL && b_head != NULL){

			if(head -> data <=b_head->data){
				temp_tail -> next = head;
				head = head->next;
			}else{
				temp_tail -> next = b_head;
				b_head = b_head->next;
			}
			temp_tail = temp_tail -> next;
		}

		if(head ==NULL){
			temp_tail->next = b_head;
		}else{
			temp_tail->next = head;
		}
		head = temp_head;
	}


};

int main() {
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	linked_list a;
	linked_list b;
	a.add_at_back(2);
	a.add_at_back(9);
	a.add_at_back(20);

	b.add_at_back(3);
	b.add_at_back(200);
	b.add_at_back(300);	
	a.print();  //2 --> 9 --> 20
	b.print();  //3 --> 200 --> 300
	a.merge(b.get_head());	
	a.print();  //2 --> 3 --> 9 --> 20 --> 200 --> 300
 
}