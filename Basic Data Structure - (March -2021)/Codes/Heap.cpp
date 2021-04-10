#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
    int  size , root;
    vector<int> a;
public:

    Heap(){
        size = 0;
        root = 1;
        a.resize(1);
    }

    int top(){   //peek the top element
        if(isEmpty()){
            cout<<"Empty Heap :(\n";
            return -1;
        }
        return a[root];

    }

    void pop(){  //return the top element and delete it
        if(isEmpty()){
             cout<<"Empty Heap :(\n";
             return;
        }
        swap(a[root], a[size--]);
        heapify(root);
    }

    void heapify(int node){  //reaarrage the nodes to maintain the property of heap
        int largest = node;
        if(left(node) <= size  && a[left(node)] > a[largest]) largest = left(node);
        if(right(node) <= size && a[right(node)] > a[largest]) largest = right(node);

        if(largest != node){
            swap(a[largest], a[node]);
            heapify(largest);
        }

    }

    void push(int val){

        int node = ++size;
        a.push_back(val);

        while(node != root){
            if(a[parent(node)] > a[node]) break;
            swap(a[node], a[parent(node)]);
            node = parent(node);
        }

    }

    bool isEmpty(){
        return size == 0;
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
        return 2*node + 1;
    }

    void print(){
        for(int i= root ;  i <= size ; i++){
            cout<< a[i]<<" ";
        }
        cout<<endl;
    }


};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 


     Heap pq;
     pq.push(5);
     pq.push(2);
     pq.push(20);
     pq.push(10);
     pq.push(-3);
     pq.print();

     cout<< pq.top() <<endl;
     pq.pop();
     cout<<pq.top()<<endl;;
     
     
    return 0;
}