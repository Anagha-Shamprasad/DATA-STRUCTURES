#include<assert.h>
#include<stddef.h>
#include<String.h>
#include "hash.h"


int main()
{
     HashTable htt;
     htt=hash_new(3);
     HashTable *ht=&htt;
     ht=add_to_hash(ht,"anagha");
     ht=add_to_hash(ht,"anagha");
     ht=delete_from_hash(ht,"anagha");
     int hash=generate_hash(ht,"anagha");

     //assert(strcmp(ht->addrlist[hash]->name,"anagha")==0);
     assert(ht->addrlist[hash]==NULL);
     //assert(strcmp("ana","ana")==0);
     return 0;
}
