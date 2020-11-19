// #ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>

struct Stack
{
	int len;
	int *dat;
	int size;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Stack duuren!",
	"Stack xooson!"};

void init(struct Stack *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Stack *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* p-ийн зааж буй Stack хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Stack *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	return p->size == 0 ? 1 : 0;
}

/* p-ийн зааж буй Stack-д x утгыг хийнэ */
void push(struct Stack *p, int x)
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

/* p-ийн зааж буй Stack-с гарган буцаана */
int pop(struct Stack *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	if (p->size != 0)
	{
		error = 2;
	}
	else
	{
		int temp = p->dat[p->size - 1];

		p->dat[p->size - 1] = p->dat[p->size];
		p->size--;

		return temp;
	}
}

/* p-ийн зааж буй Stack-н орой элементийг буцаанаутгуудыг хэвлэнэ */
int top(struct Stack *p)
{
	/* Энд орой элементийг буцаах үйлдэл хийнэ */
	if (p->size == 0)
	{
		error = 2;
	}
	else
	{
		return p->dat[p->size - 1];
	}
}

/* p-ийн зааж буй Stack-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Stack *p)
{
	return p->size;
}

void print(struct Stack *p)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
	for (int i = 0; i < p->len; i++)
		printf("[%d]", p->dat[i]);
}
