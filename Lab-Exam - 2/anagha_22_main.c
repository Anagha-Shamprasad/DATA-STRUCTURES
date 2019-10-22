#include <stdint.h>
#include<stdio.h>
#include <assert.h>
#include "anagha_22.h"

void test_sort( int32_t data[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (data[idx] <= data[idx+1]);		
	}
}

void test_heap()
{
	int32_t data[] = { 1100,1250, 1500, 5000, 1045, 1930, 1300, 2000, 1800, 1000}; 
	Heap heap = heap_new(data, 10);	
	heap_insert(&heap, 47);
	heap_test(&heap);
	assert(heap_get_max(&heap) == 93);
	assert(heap_extract_max(&heap) == 93);
	heap_test(&heap);
	assert(heap_size(&heap) == 10);
    int i;
	Heap *temp=heap_sort(&heap);
    for(i=0;i<10;i++)
    {
        printf("%d\t",heap.timestamp[i]);
    }
    
	test_sort(heap.timestamp, 10);

}

int main()
{
	test_heap();
	return 0;
}