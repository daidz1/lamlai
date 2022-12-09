#include<iostream>
using namespace std;
struct node
{
	
	int data;
	struct node *left;
	struct node *right;
};
struct node *root =NULL;
void insert(int data){
	struct node *tempNode=(struct node*) malloc(sizeof(struct node));
	struct node *current;
	struct node *parent;

	tempNode->data =data;
	tempNode->left=NULL;
	tempNode->right=NULL;
	// kiem tra cay co trong ko
	if(root==NULL){
		root=tempNode;
	}
	else {
		current=root;
		parent=NULL;
	}
	while(1){
		parent=current;
		//duyet cay ben trai
		if(data<parent->data){
			current=current->left;

			//chen vao cay ben trai
			if(current==NULL){
				parent->left=tempNode;
				return;
			}
		}
		// duyet cay ben phai 
		else{
			current=current->right;

			//chen vao cay phai
			if(current==NULL){
				parent->right=tempNode;
				return;
			}
		}
	}
}
struct node* search(int data){
	struct node *current=root;
	cout<<"truy cap phan tu cua cay";
	while(current->data != data){
		if(current != NULL)
			cout<<current->data;

		// chuyen toi cay con ben trai
		if(current->data>data){
			current=current->left;
		}
		//chuyen toi cay con ben phai
		else{
			current=current->right;
		}
		//khong tim thay
		if(current==NULL){
			return NULL;
		}
	}
	return current;
}
void pre_order_traversal(struct node* root){
	if(root != NULL){
		cout<< root->data;
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}
void inorder(struct node* root){
	if(root !=NULL){
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}
}
void post(struct node* root){
	if(root!=NULL){
		post(root->left);
		post(root->right);
		cout<<root->data;
	}
}
int main(){
	int i;
	int a[10]={1,2,4,5,6,7,8,3,45,98};
	for(i=0;i<10;i++ ){
		insert(a[i]);
	}
	i=1;
	struct node * temp=search(i);
	if(temp!=NULL){
		cout<<"tim thay "<<temp->data;
	}else{
		cout<<"meo tim thay";

	}
	 i=1;
	temp=search(i);
	if(temp!=NULL){
		cout<<"tim thay"<<temp->data;

	}
	else{
		cout<<"meo tim thay";
	}
	cout<<"duyet";
	pre_order_traversal(root);
	inorder(root);
	post(root);
}