#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(){
        value = 0;
        left  = NULL;
        right = NULL;
    }

    Node(int val){
        value = val;
        left  = NULL;
        right = NULL;
    }

};

class BST {
private:
    Node *root;
public:
    BST(){
        root = NULL;
    }
    BST(int rootValue){
        root = new Node(rootValue);
    }
    Node* getRoot(){
        return root;
    }
    
    Node* insert(Node* currentNode, int val){
        if(currentNode == NULL){
            return new Node(val);
        }else if(currentNode -> value > val){
            currentNode -> left = insert(currentNode->left, val);
        }else if(currentNode -> value < val){
            currentNode -> right = insert(currentNode->right, val);
        }
        return currentNode;
    }

    Node* del(Node* currentNode, int val){
        if(currentNode == NULL){
            return NULL;
        }
        if(currentNode -> value > val){
            currentNode -> left = del(currentNode->left, val);
        }else if(currentNode -> value < val){
            currentNode -> right = del(currentNode->right, val);
        }else{ //we want to delte currentNode
            if(currentNode->left == NULL and currentNode->right == NULL){
                delete(currentNode);  //0 child
                return NULL;
            }else if(currentNode->right == NULL){ //only left child
                Node* temp = currentNode->left;
                delete(currentNode);
                return temp;
            }else if(currentNode->left == NULL){  //only right child
                Node* temp = currentNode->right;
                delete(currentNode);
                return temp;
            }else{ //both children
                int nge = find_smallest(currentNode->right);
                currentNode->value = nge;
                currentNode -> right = del(currentNode->right, nge);
                return currentNode;
            }
        }
        return NULL;
    }

    int find_smallest(Node* currentNode){
        if(currentNode->left == NULL){
            return currentNode->value;
        }else return find_smallest(currentNode->left);
    }

    Node* search(Node* currentNode, int val){
        if(currentNode == NULL)
            return NULL;

        if(currentNode->value == val)
            return currentNode;
        else if(currentNode-> value < val)
            return search(currentNode->right, val);
        else
            return search(currentNode->left, val);
    }

    void print(Node* currentNode){
        if(currentNode == NULL) return;
        print(currentNode->left);
        cout<<currentNode -> value<< " ";
        print(currentNode->right);
    }

    void insertBST(int val){
        if(root == NULL){
            root = new Node(val);
            return;
        }
        root = insert(root, val);
    }

    void deleteBST(int val){
        if(root == NULL){
            return;
        }else root = del(root, val);
    }
    void printBST(){
        print(getRoot());
    }

};
signed main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    
    BST bst(10);
    bst.insertBST(4);
    bst.insertBST(13);
    bst.insertBST(6);

    bst.print(bst.getRoot());
    cout<<endl;
    bst.deleteBST(10);
    bst.printBST();
    
    return 0;
}