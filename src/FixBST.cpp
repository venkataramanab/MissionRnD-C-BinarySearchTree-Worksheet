/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>

void swap_nodes(struct node *a, struct node *b);
void helperFunc2(struct node *root, struct node **temp, struct node **ptr1, struct node **ptr2);
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void fix_bst(struct node *root){
	if (root == NULL)
		return;
	struct node *ptr1 = NULL, *ptr2 = NULL;
	struct node **parentData=(struct node **)malloc(sizeof(node));
	*parentData = NULL;
	helperFunc2(root, parentData, &ptr1, &ptr2);
	swap_nodes(ptr1, ptr2);
}
void helperFunc2(struct node *root, struct node **temp, struct node **ptr1, struct node **ptr2){
	if (root){
		helperFunc2(root->left, temp, ptr1, ptr2);
		if ((*temp) && (root->data < (*temp)->data)){
			if (*ptr1 == NULL)
				*ptr1 = *temp;
				*ptr2 = root;
		}
		*temp = root;
		helperFunc2(root->right, temp, ptr1, ptr2);
	}
}
void swap_nodes(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}