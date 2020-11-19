// #ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>

struct Queue
{
	int len;
	int *dat;
	int size;
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Queue duuren!",
	"Queue xooson!"};

void init(struct Queue *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Queue *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* p-ийн зааж буй Queue хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Queue *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	return p->size == 0 ? 1 : 0;
}

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void enqueue(struct Queue *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	if (p->size > p->len - 1)
	{
		error = 1;
	}
	else
	{
		p->dat[p->size] = x;
		p->size++;
	}
}

/* p-ийн зааж буй Queue-с гарган буцаана */
int dequeue(struct Queue *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	if (p->size == 0)
	{
		error = 2;
	}
	else
	{
		int temp = p->dat[0];
		for (int i = 0; i < p->size; i++)
		{
			p->dat[i] = p->dat[i + 1];
		}
		p->size--;
		return temp;
	}
}

/* p-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void print(struct Queue *p)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
	for (int i = 0; i < p->len; i++)
		printf("[%d]", p->dat[i]);
}

/* p-ийн зааж буй Queue-н хамгийн эхний элементийн утгыг буцаана.
   Гаргах үйлдэл хийхгүй.
 */
int front(struct Queue *p)
{
	return p->dat[0];
}
/* p-ийн зааж буй Queue-н хамгийн сүүлийн элементийн утгыг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int back(struct Queue *p)
{
	return p->dat[p->size - 1];
}
/* p-ийн зааж буй Queue-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Queue *p)
{
	return p->size;
}
