#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "bst.h"
#include"..\Queues\queue.h"


int main()
{
BST bst = bst_new();
BST *tree = &bst;
//1. Design a BST class with methods to add element, search element, number of elements and delete requested element
assert(lookup(tree,90)==0);
tree = add_node(tree,50);
assert((tree->root->left==NULL) && (tree->root->right==NULL));
tree=delete_node(tree,100);
tree = add_node(tree,20);
tree=delete_node(tree,20);
tree = add_node(tree,30);
tree = add_node(tree,60);
tree = add_node(tree,70);
assert(lookup(tree,70)==1);
tree = add_node(tree,35);
tree = add_node(tree,40);
tree = add_node(tree,20);
tree = add_node(tree,25);
tree = add_node(tree,15);
tree=delete_node(tree,100);
tree=delete_node(tree,25);
tree=delete_node(tree,35);
tree=delete_node(tree,60);
tree=delete_node(tree,50);
assert(tree->root->data==70);
tree=delete_node(tree,70);
assert(tree->root->data==40);
assert(tree->count == 4);

//2. Add methods to in-order, pre-order, post-order and level-order traversals
printf("\nIn-order: ");
bst_inorder(tree);
printf("\nPre-Order: ");
bst_preorder(tree);
printf("\nPost-Order: ");
bst_postorder(tree);
printf("\nLevel Order: ");
level_order(tree);

//3.Finding Height of a binary tree
assert(max_depth(tree)==4);

//4.Finding count of the number of leaf nodes
assert(leaf_count(tree)==1);

//5. Finding minimum and maximum element in a tree
assert(find_min(tree)==15);
assert(find_max(tree)==40);

//6.Ascending order
printf("\nAscending Order: ");
bst_inorder(tree);

//7.Descending Order
printf("\nDescending Order: ");
bst_descending(tree);

return 0 ;
}
