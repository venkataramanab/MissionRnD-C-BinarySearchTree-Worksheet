/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>
int get_right_subtree_sum(struct node *root);
int get_left_subtree_sum(struct node *root);
int get_subtree_sum(struct node *root);
struct node{
	struct node * left;
	int data;
	struct node *right;
};

//-----------gets height of a tree--------------
int get_height(struct node *root){
	if (root == NULL)
		return 0;
//----------for left branch---------------------
	int left = get_height(root->left);
//----------for right branch--------------------
	int right = get_height(root->right);
//----------we should include root node also----
	return left > right ? left + 1 : right + 1;
}
//-------to get sum of nodes in a branch--------
int get_subtree_sum(struct node *root){
//-----------if no root sum is zero-------------
	if (root == NULL)
		return 0;
//----calculating left and right child sum------
	int childSum = get_subtree_sum(root->left) + get_subtree_sum(root->right);
//-----adding root->data to child sum-----------
	return childSum + root->data;
}
//-------to get sum of left sub tree------------
int get_left_subtree_sum(struct node *root){
	if (root)
		return get_subtree_sum(root->left);
	return -1;
}
//--------to get sum of right sub tree----------
int get_right_subtree_sum(struct node *root){
	if (root)
		return get_subtree_sum(root->right);
	return -1;
}

