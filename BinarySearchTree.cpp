  #include<bits/stdc++.h>
using namespace std;
struct  node{
	int data;
	node *left, *right;
};

class BST{
public:
	node* root;
	int size;

	BST(){
		root = NULL;
		size=0;
	}

	struct node* insert(struct node* root, int val){
		if(root == NULL){
			size++;
			struct node* temp = new node;
			temp->data = val;
			temp->left = NULL;
			temp->right = NULL;
			return temp;
		}

		if(root->data > val){
			root->left = insert(root->left, val);
		}else if(root->data < val){
			root->right = insert(root->right, val);
		}
		return root;
	}

	struct node* deleteNode(struct node* root, int val){
		if(root == NULL){
			return root;
		}

		if(root->data >  val){
			root->left = deleteNode(root->left, val);
		}else if(root->data < val){
			root->right = deleteNode(root->right, val);
		}else{

			if(root->left == NULL){
				size--;
				struct node* temp = root->right;
				free(root);
				return temp;
			}

			if(root->right == NULL){
				size--;
				struct node* temp = root->left;
				free(root);
				return temp;
			}

			struct node* temp = minNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
		return root;
	}

	bool find(struct node* root, int val){
		if(root == NULL){
			return false;
		}

		if(root->data == val){
			return true;
		}else if(root->data > val){
			return find(root->left, val);
		}else{
			return find(root->right, val);
		}
	}

	struct node* minNode(struct node* root){
		if(root == NULL || root->left == NULL){
			return root;
		}
		return minNode(root->left);
	}

	struct node* maxNode(struct node* root){
		if(root == NULL || root->right == NULL){
			return root;
		}
		return maxNode(root->right);
	}

	void inorder(struct node* root){
		if(root == NULL) return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

};
int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	BST tree;

	tree.root = tree.insert(tree.root, 40);
	tree.root = tree.insert(tree.root, 120);
	tree.root = tree.insert(tree.root, 12);
	tree.root = tree.insert(tree.root, 19);

	tree.inorder(tree.root); cout<<endl;

	tree.root = tree.deleteNode(tree.root, 40);

    tree.inorder(tree.root); cout<<endl;

    cout<<tree.size<<endl;

}
