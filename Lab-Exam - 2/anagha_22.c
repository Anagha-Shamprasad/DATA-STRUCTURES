#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "anagha_22.h"


static void _swap_(int32_t *data1, int32_t *data2) {
	int32_t temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

static void _heapify_ (int32_t data[], uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (data[child+1] > data[child]){
				++child;
			}
		}
		if (data[parent] >= data[child]) {
			break;
		}
		_swap_(&data[parent], &data[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_heap_(int32_t data[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child] <= data[child/2]);
	}

}

Heap* heap_test(Heap *heap)
{
	_test_heap_(heap->timestamp, heap->size);
}

Heap heap_new(int32_t data[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(data, len, idx);
	}
	heap.size = len;
	memcpy(heap.timestamp, data, (len+1) * sizeof(int32_t));
	_test_heap_(heap.timestamp, heap.size);

	return heap;
}

Heap* heap_sort(Heap *heap) {
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = heap->size;

	for (idx = heap->size; idx > 1; idx--) {
		_swap_(&heap->timestamp[idx], &heap->timestamp[1]);
		_heapify_(heap->timestamp, idx-1, 1);
	}

	return heap;
}


Heap*	heap_insert(Heap *heap, int32_t key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->timestamp[parent] < key) {
		heap->timestamp[loc] = heap->timestamp[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->timestamp[loc] = key;
	return heap;

}

int32_t		heap_get_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->timestamp[1];

}

int32_t	heap_extract_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	int32_t max = heap->timestamp[1];	
	_swap_(&heap->timestamp[1], &heap->timestamp[heap->size]);
	--heap->size;
	_heapify_(heap->timestamp, heap->size, 1);

	return max;
}

uint32_t	heap_size(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}