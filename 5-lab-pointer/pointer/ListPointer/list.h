#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct List
{
	struct Node *root;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"List xooson!",
	"Bairlald oruulax bolomjgui!",
	"Bairlaas gargax bolomjgui!"};
void init(struct List *p, int n)
{
	p->root = NULL;
}

void release(struct List *p)
{
	free(p->root);
	p->root = NULL;
}
/* p-ийн зааж буй List хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct List *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
}
/* p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
   pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
 */
void insert(struct List *p, int x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int removes(struct List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
}
/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
}
/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct List *p, int x)
{
}

#endif
