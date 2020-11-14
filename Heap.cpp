#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
	int a[100], size = 0, root = 1;
public:
	int top(){
		if(empty()){
			cout<<"Heap UnderFlow\n";
			return -1;
		}

		return a[root];
	}

	void heapify(int node){
		int largest = node;
		if(left(node) <= size && a[left(node)] > a[largest]) largest = left(node);
		if(right(node) <= size && a[right(node)] > a[largest]) largest = right(node);

		if(largest != node){
			swap(a[largest], a[node]);
			heapify(largest);
		}
	}

	void pop(){
		swap(a[root], a[size]);
		size--;
		heapify(root);
	}

	bool empty(){
		return size == 0;
	}

	void push(int val){
		int node = ++size;
		a[node] = val;
		while(node!=root){
			if(a[parent(node)] > a[node]) break;
			swap(a[node], a[parent(node)]);
			node = parent(node);
		}
	}

	int getSize(){
		return size;
	}

	int parent(int node){
		return node/2;
	}

	int left(int node){
		return 2*node;
	}

	int right(int node){
		return 2*node+1;
	}
};


int main() {
 	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Heap pq;
	pq.push(5);
	pq.push(6);
	cout<< pq.getSize()<<endl; //2
	cout<<pq.empty()<<endl; //0
	cout<<pq.top()<<endl; //6
	pq.push(9);
	cout<<pq.top()<<endl; //9
	pq.pop();
	cout<<pq.top()<<endl; //6
	pq.pop();
	cout<<pq.top()<<endl;
	pq.pop();         //5
	cout<<pq.empty()<<endl; //1

}