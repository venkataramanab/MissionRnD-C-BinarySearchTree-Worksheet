/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
int *inorderFun(struct node *root, int *arr);
int *preorderFun(struct node *root, int *arr);
int *postorderFun(struct node *root, int *arr);

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	inorderFun(root, arr);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	preorderFun(root, arr);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	postorderFun(root, arr);
}
int *inorderFun(struct node *root, int *arr){
	if (root){
		arr = inorderFun(root->left, arr);
		*arr = root->data;
		arr = inorderFun(root->right, arr + 1);
	}
	return arr;
}
int *preorderFun(struct node *root, int *arr){
	if (root){
		*arr = root->data;
		*arr++;
		arr = preorderFun(root->left, arr);
		arr = preorderFun(root->right, arr);
	}
	return arr;
}
int *postorderFun(struct node *root, int *arr){
	if (root){
		arr = postorderFun(root->left, arr);
		arr = postorderFun(root->right, arr);
		*arr = root->data;
		return arr + 1;
	}
	return arr;
}


