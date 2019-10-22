#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 32
#define Takeoff 0
#define Landing 1

typedef struct _heap_ Heap;
typedef struct _info_ Info;

struct _info_ 
{
    int32_t timestamp;
    int32_t plane_no;
    int32_t take_or_land;
};

struct  _heap_
{
	uint32_t size;
	Info  timestamp[HEAP_MAX_SIZE];
};



Heap heap_new(int32_t data[], uint32_t len);
Heap* heap_sort(Heap *heap);
Heap* heap_insert(Heap *heap, int32_t key);
Heap* heap_test(Heap *heap);
int32_t	heap_get_max(Heap *heap);
int32_t	heap_extract_max(Heap *heap);
uint32_t heap_size(Heap *heap);

#endif