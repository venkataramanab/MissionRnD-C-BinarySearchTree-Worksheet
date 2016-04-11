/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node *helperFun(int *arr, int start, int end);
struct node * new_node_spec(int data);
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL || len<0)
		return NULL;
	struct node *root = NULL;
	root = helperFun(arr, 0, len);
	return root;
}
struct node *helperFun(int *arr, int start, int end){
	if (start <= end){
		int mid = (end + start) / 2;
		struct node *root = new_node_spec(arr[mid]);
		root->left = helperFun(arr, start, mid - 1);
		root->right = helperFun(arr, mid+1, end);
		return root;
	}
	return NULL;
}

