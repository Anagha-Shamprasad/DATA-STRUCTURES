#ifndef _INCLUDED_BST_
#define _INCLUDED_BST_
#include<stdint.h>
#include"..\Queues\queue.h"

typedef struct  _tree_node Node;
typedef struct  _bst_ BST;

struct _tree_node
{
	int32_t data;
	Node *left;
	Node *right;
};

struct _bst_
{
	Node *root;
	uint32_t count;
};

BST bst_new();
uint32_t bst_count(BST *tree);
uint32_t lookup(BST* tree,int32_t ele);
BST* add_node(BST *tree,int32_t element);
BST* delete_node(BST* tree,int32_t key);
void bst_inorder(BST *tree);
void bst_preorder(BST* tree);
void bst_postorder(BST* tree);
void level_order(BST *tree);
void bst_descending(BST *tree);
int32_t find_min(BST *tree);
int32_t find_max(BST *tree);
uint32_t leaf_count(BST* tree);
uint32_t max_depth(BST* tree);

#endif
