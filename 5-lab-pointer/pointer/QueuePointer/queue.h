#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node {
	int data;
	struct Node *next;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Queue xooson!"
};
void init(struct Queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}
void release(struct Queue *q)
{
	free(q->head);
	q->head = NULL;
	free(q->tail);
	q->tail = NULL;
}
/* q-ийн зааж буй Queue хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct Queue *q)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
}
/* q-ийн зааж буй Queue-д x утгыг хийнэ */
void enQueue(struct Queue *q, int x)
{
   	/* Энд оруулах үйлдлийг хийнэ үү */
}

/* q-ийн зааж буй Queue-с гарган буцаана */
int deQueue(struct Queue *q)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
}

/* q-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void print(struct Queue *q)
{
  		/* Энд хэвлэх үйлдлийг хийнэ үү */
}

/* q-ийн зааж буй Queue-н хамгийн эхний элементийн утгыг буцаана.
   Гаргах үйлдэл хийхгүй.
 */
int front(struct Queue *q)
{
   	
}
/* q-ийн зааж буй Queue-н хамгийн сүүлийн элементийн утгыг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int back(struct Queue *q)
{
	
}
/* q-ийн зааж буй Queue-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Queue *q)
{
  	
}
/* q-ийн зааж буй queue-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct List *q, int x)
{

}

#endif
