
#include <stdio.h>
#include "Heap.h"
int main()
{
	/* List үүсгэн, эхлүүлэх */
	struct Heap heap;
	int n=15;
	init(&heap, n);
	int t, x, pos;
	int a[15]={	15,20,14,2,16,18,22,17,3,5,7,21,26,1,8};
	build_heap(&heap,a,15);
	breadth_first(&heap);
	sort_heap(&heap);
	breadth_first(&heap);
	if(error) {
        printf("heap hooson");
	}
	print_array(heap.dat,n);
	release(&heap);
	return 0;
}
