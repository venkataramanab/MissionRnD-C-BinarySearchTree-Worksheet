/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>
int getHeight(struct node *root);
int countNodes(struct node *root);
int *helperFunc(struct node* root, int *arr, int level);
struct node{
	struct node * left;
	int data;
	struct node *right;
};
int getHeight(struct node *root){
	if (root == NULL)
		return 0;
	//----------for left branch---------------------
	int left = getHeight(root->left);
	//----------for right branch--------------------
	int right = getHeight(root->right);
	//----------we should include root node also----
	return left > right ? left + 1 : right + 1;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
		return NULL;
	int height = getHeight(root);
	int nodeCount = countNodes(root);
	int *arr = (int*)malloc(sizeof(int)*nodeCount);
	int *ptr = arr;
	for (int i = 0; i < height; i++){
		ptr=helperFunc(root,ptr,i);
	}
	return arr;
}
int *helperFunc(struct node* root,int *arr,int depth){
	if (depth==0){
		*arr = root->data;
		return arr + 1;
	}
	if (root->right)
		arr=helperFunc(root->right, arr, depth - 1);
	if (root->left)
		arr=helperFunc(root->left, arr, depth - 1);
	return arr;
}
int countNodes(struct node *root){
	if (root)
		return 1 + countNodes(root->left) + countNodes(root->right);
	return 0;
}
