#include <stdio.h>
#include <stdlib.h>

struct List
{
	int len;
	int *dat;
	int size;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"List duuren!",
	"List xooson!",
	"Bairlald oruulax bolomjgui!",
	"Bairlaas gargax bolomjgui!"};

void init(struct List *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct List *p)
{
	free(p->dat);
	p->dat = NULL;
}
/* p-ийн зааж буй List хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct List *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
}
/* p-ийн зааж буй List дүүрсэн бол 1 үгүй бол 0-ийг буцаана */
int isFull(struct List *p)
{
	/*энд жагсаалт дүүрсэн эсэхийг шалгах үйлдлийг хийнэ*/
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
int remove(struct List *p, int pos)
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
int search(struct List *p, int x)
{
}

int main()
{
	/* List үүсгэн, эхлүүлэх */
	struct List st;
	init(&st, 10);
	int t, x, pos;

	while (1)
	{
		printf(" 1: insert, 2: remove,  3: empty, 4: isFull 5: search, 6: print,"
			   "7: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t)
		{
		case 1:
			printf("Oruulax utga: ");
			scanf("%d", &x);
			printf("Oruulax bairlal: ");
			scanf("%d", &pos);
			insert(&st, x, pos);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga %d-d orloo\n", x, pos);

			break;
		case 2:
			printf("gargax bairlal: ");
			scanf("%d", &pos);
			x = remove(&st, pos);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utgiig %d bairlalaas gargalaa\n", x, pos);
			break;
		case 3:
			if (empty(&st))
				printf("List xooson\n");
			else
				printf("List xooson bish\n");
			break;
		case 4:
			if (isFull(&st))
				printf("List duuren\n");
			else
				printf("List duureegui\n");
			break;
		case 5:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = search(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				printf("%d utga %d bairlald oldloo\n", x, pos);
			break;
		case 6:
			print(&st);
			break;
		default:
			exit(0);
		}
	}
	/* List-ийн эзэмшсэн нөөцийг чөлөөлөх */
	release(&st);
	return 0;
}
