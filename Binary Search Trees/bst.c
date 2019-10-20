#include<stdint.h>
#include<stdlib.h>
#include<assert.h>
#include<stddef.h>
#include<stdbool.h>
#include<stdio.h>

#include"bst.h"
#include"..\Queues\queue.h"


BST bst_new()
{
	BST tree={NULL,0};
	return tree;
}

static Node* create_new_node(int32_t ele)
{
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=ele;
	node->left=NULL;
	node->right=NULL;
	return node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree!=NULL);
	return tree->count;
}

uint32_t lookup(BST* tree,int32_t key)
{
    assert(tree!=NULL);
    Node *temp=tree->root;
    while(temp!=NULL)
    {
        if(temp->data==key) break;
        else
        {
            if(key>temp->data) temp=temp->right;
            else temp=temp->left;
        }
    }

    return temp!=NULL;
}

BST* add_node(BST *tree, int32_t ele)
{
	assert(tree!=NULL);

	Node *temp=create_new_node(ele);

	if(tree->root==NULL)
	{
		tree->root=temp;
		tree->count++;
		return tree;
	}

	Node *cur=tree->root;

	while(true)
	{
		if(ele<cur->data)
		{
			if(cur->left==NULL)
			{
				cur->left=temp;
				tree->count++;
				break;

			}
			else cur=cur->left;
		}

		else if(ele>cur->data)
		{
			if(cur->right==NULL)
			{
				cur->right=temp;
				tree->count++;
				break;
			}
			else cur=cur->right;

		}

		else break;
	}

	return tree;
}
static BST* single_or_no_child_delete(BST* tree,Node *node,Node*parent)
{
    int key=node->data;
    if((node->left==NULL) && (node->right==NULL))
    {
        if(key>parent->data) parent->right=NULL;

        else parent->left=NULL;
    }

    else if((node->left==NULL)&&(node->right!=NULL))
    {
        if(key>parent->data) parent->right=node->right;
        else parent->left=node->right;
    }

    else if((node->left!=NULL)&&(node->right==NULL))
    {
        if(key>parent->data) parent->right=node->left;
        else parent->left=node->left;
    }

    return tree;
}

static BST* root_delete(BST* tree)
{
    Node *cur,*just;
    Node *node=tree->root;
    if((node->left==NULL) && (node->right!=NULL))
    {
        cur=node->right;
        just=node;
        while(cur->left!=NULL)
        {
            just=cur;
            cur=cur->left;
        }
    }
    else if((node->left!=NULL)&&(node->right==NULL))
    {
        cur=node->left;
        just=node;
        while(cur->right!=NULL)
        {
            just=cur;
            cur=cur->right;
        }
    }

    tree=single_or_no_child_delete(tree,cur,just);
    node->data=cur->data;
    free(cur);
    tree->count--;
    return tree;
}

BST* delete_node(BST* tree, int32_t key)
{
    assert(tree!=NULL);
    if(tree->root==NULL) return tree;
    Node *temp=tree->root;
    if((temp->data==key) && (temp->left==NULL) &&(temp->right==NULL))
    {
        tree->root=NULL;
        free(temp);
        tree->count--;
        return tree;
    }
    Node *prev=temp;

    while(temp!=NULL)
    {
        if(temp->data==key) break;
        else
        {
            prev=temp;
            if(key>temp->data) temp=temp->right;
            else temp=temp->left;
        }
    }

    if(temp==NULL) return tree;


    if(temp->left!=NULL && temp->right!=NULL) //For a node with 2 children
    {
        Node *cur=temp->right;
        Node *just=temp;
        while(cur->left!=NULL)
        {
            just=cur;
            cur=cur->left;
        }

        prev=just;
        temp=cur;
        tree=single_or_no_child_delete(tree,cur,just);
        prev->data=temp->data;

    }

    else if(temp->data==tree->root->data) //If its a root node with one child
    {
        tree=root_delete(tree);
        return tree;
    }
    else
        tree=single_or_no_child_delete(tree,temp,prev);

    free(temp);
    tree->count--;
    return tree;
}

static void _inorder_(Node *node)
{
	if(node)
	{
		_inorder_(node->left);
		printf("%d\t", node->data );
		_inorder_(node->right);
	}
}

void bst_inorder(BST *tree)
{
	assert(tree!=NULL);
	_inorder_(tree->root);
}

static void _preorder_(Node *node)
{
	if(node)
	{
	    printf("%d\t", node->data );
		_preorder_(node->left);
		_preorder_(node->right);
	}
}

void bst_preorder(BST *tree)
{
	assert(tree!=NULL);
	_preorder_(tree->root);
}

static void _postorder_(Node *node)
{
	if(node)
	{
		_postorder_(node->left);
		_postorder_(node->right);
		printf("%d\t", node->data );
	}
}
void bst_postorder(BST *tree)
{
	assert(tree!=NULL);
	_postorder_(tree->root);
}

void level_order(BST *tree)
{
    assert(tree!=NULL);
    Node *temp;
    Queue que=queue_new(tree->count);
    Queue *q=&que;
    Result res;
    q=q_add(q,&res,tree->root->data);

    while(queue_status(q)!=QUEUE_EMPTY)
    {
        q=q_delete(q,&res);
        temp=(Node*)res.data;
        if(temp->left) q_add(q,&res,temp->left->data);
        if(temp->right) q_add(q,&res,temp->right->data);
        printf("%d\t",temp->data);
    }
}

static void _descendingorder_(Node *node)
{
	if(node)
	{
		_descendingorder_(node->right);
		printf("%d\t", node->data );
		_descendingorder_(node->left);
	}
}

void bst_descending(BST *tree)
{
	assert(tree!=NULL);
	_descendingorder_(tree->root);
}
int32_t find_min(BST *tree)
{
    assert(tree!=NULL);
    if(tree->root==NULL) return false;

    Node *cur=tree->root;
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur->data;

}
int32_t find_max(BST *tree)
{
    assert(tree!=NULL);
    if(tree->root==NULL) return false;

    Node *cur=tree->root;
    while(cur->right!=NULL)
    {
        cur=cur->right;
    }
    return cur->data;

}

static uint32_t find_depth(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {

        int left_depth = find_depth(node->left);
        int right_depth = find_depth(node->right);


        if (left_depth > right_depth)
            return(left_depth + 1);
        else return(right_depth + 1);
    }
}

uint32_t max_depth(BST *tree)
{
    assert(tree!=NULL);
    int ans = find_depth(tree->root);
    return ans;
}

static uint32_t actual_leaf_count(Node *node)
{
    if(node==NULL) return 0;
    if(node->left==NULL && node->right==NULL) return 1;
    return actual_leaf_count(node->left)+actual_leaf_count(node->right);
}
uint32_t leaf_count(BST* tree)
{
    assert(tree!=NULL);
    int ans=actual_leaf_count(tree->root);
    return ans;
}
