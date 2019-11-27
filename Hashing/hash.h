#include<stdio.h>

typedef struct _node_ Node;
typedef struct _addr_ HashTable;
#define MAX_VALUE 3

struct _node_{
    char name[20];
    Node *next;
};

struct _addr_{
    Node** addrlist;
    int size;
};

HashTable hash_new(int size);
int lookup(HashTable *ht,char ele[]);
HashTable* add_to_hash(HashTable *ht,char ele[]);
HashTable* delete_from_hash(HashTable *ht,char ele[]);
int generate_hash(HashTable *ht,char ele[]);
