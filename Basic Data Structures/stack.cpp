#include<bits/stdc++.h>
using namespace std;

class Stack {
private :
	int a[100], size = 0, max_limit = 100, maxi[100], mini[100];
public:

	int get_size(){
		return size;
	}

	void push(int val){
		if(size == 100){
			cout<<"Stack overflow\n";
			return;
		}	
		a[size] = val;
		maxi[size] = (size ==0 ? val : max(maxi[size-1], val));
		mini[size] = (size==0  ? val : min(mini[size-1], val));
		size ++;
	}

	int pop(){
		if(size == 0){
			cout<<"Stack underflow\n";
			return -1;
		}
		return a[--size];
	}

	int peek(){
		if(size == 0){
			cout<<"Stack is Empty\n";
			return -1;
		}
		return a[size-1];
	}

	void update_top(int val){
		if(size == 0){
			cout<<"Stack is Empty\n";
		}
		a[size-1] = val;
		maxi[size-1] = (size == 1 ? val : max(maxi[size-2], val));
		mini[size-1] = (size == 1 ? val : min(mini[size-2], val));
	}

	int get_min(){
		if(size == 0){
			cout<<"Stack is Empty\n";
		}
		return mini[size-1];
	}
	int get_max(){
		if(size == 0){
			cout<<"Stack is Empty\n";
		}
		return maxi[size-1];

	}
	bool is_empty(){
		return (size == 0);
	}

};


struct node {
	int data;
	node *next;
};

class StackLL{
private:
	node *head, *tail;
	int size;
public:
	StackLL(){
		head=NULL;
		tail=NULL;
		size = 0; 
	}


	void push(int val){
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


	int  peek(){
		if(size == 0){
			cout<<"Stack underflow\n";
			return -1;
		}
		return head -> data;
	}

	int pop(){
		if(size == 0){
			cout<<"Stack underflow\n";
			return -1;
		}
		node *prev, *cur = head;
		int temp = head -> data;
		head = cur ->next;
		free(cur);
		size--;
		return temp;
	}

	int get_size(){
		return size;
	}

};

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);	

	Stack a;
	a.push(4);
	a.push(5);
	a.push(1);
	cout<<a.get_min() <<" "<<a.get_max()<<endl;   // 1 5
	a.push(10);
	cout<<a.get_min() <<" "<<a.get_max()<<endl;  // 1 10

	cout<<"size : "<<a.get_size()<<endl; // 4
	cout<<"peek: "<<a.peek()<<endl; // 10

	cout<<"pop : "<<a.pop()<<endl; // 10
	cout<<"pop: "<<a.pop()<<endl; // 1

	cout<<"size: "<<a.get_size()<<endl; //2  

	
}