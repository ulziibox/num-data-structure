#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Heap
{
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Heap duuren!",
	"Heap hooson!",
};

void init(struct Heap *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Heap *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* a хүснэгтийн i болон j дугаар элементийн байрыг солих */
void swap(int *a, int i, int j)
{
}
/*p-ийн зааж буй Heap-д шинээр нэмэгдсэн idx зангилааны элементийг эцэгтэй нь жишиж байрыг солих замаар зөв байрлалд оруулах*/
void heap_Up(struct Heap *p, int idx)
{
	// etsegee baga, esvel root boloh vyd duusna
}
/*p-ийн зааж буй Heap-ийн idx элементийг хүүхдүүдтэй нь жишиж байрыг солих замаар зөв байрлалд оруулах*/
void heap_Down(struct Heap *p, int idx)
{
}

/* p-ийн зааж буй Heap-д x утгыг нэмэн Heap_up үйлдлийн туслажтай зөв байрлалд оруул */
void add(struct Heap *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
}
/* p-ийн зааж буй Heap-д а хүснэгтийн бүх элементийг add үйлдлийн туслажтай нэм*/
void build_heap(struct Heap *p, int *a, int n)
{
}
/* p-ийн зааж буй Heap-ийн үндэс элементийг устган 
(үндэс элементийг heap-ийн хамгийн сүүлийн элементтэй байрыг солино) 
heap_Down үйлдлийн туслажтай heap-ийг зас*/
/*  */
void removeE(struct Heap *p)
{
	//swap hiine
	//size aa negeer hasna
	//heap_down hiine
}
/* p-ийн зааж буй Heapийн элементүүдийг устгах (removeE үйлдлийг ашиглан) замаар эрэмбэлэх үйлдэлийг гүйцэтгэ*/
void sort_heap(struct Heap *p)
{
	//removeE geer heapiig hooslono
}
/* p-ийн зааж буй Heap -ийн элементүүдэд түвшинээр гүйн хэвлэ */
void breadth_first(struct Heap *p)
{
	if (p->size > 0)
		print_array(p->dat, p->size);
	else
		error = 2;

	//modoogr guih 2 arga baidag 1. tuvshin 2. guneer
}
/* n элементтэй а хүснэгтийн утгыг хэвлэ */
void print_array(int *a, int n)
{
}
#endif
