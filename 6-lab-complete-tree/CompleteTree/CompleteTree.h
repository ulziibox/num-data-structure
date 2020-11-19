#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Tree
{
	int len;  // Нийт багтаамж
	int size; // Одоогийн хэмжээ
	int *dat; // Өгөгдөл хадгалах хүснэгтийг заах хаяг
};

int error = 0;
const char error_msg[][50] = {
	"",
	"Mod duuren!",
	"Mod hooson!",
};

void init(struct Tree *p, int n)
{
	p->len = n;
	p->size = 0;
	p->dat = (int *)malloc(sizeof(int) * n);
}

void release(struct Tree *p)
{
	free(p->dat);
	p->dat = NULL;
}

/* p-ийн зааж буй Tree-с x тоог хайн олдсон байрлалыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Tree *p, int x)
{
}

/* p-ийн зааж буй модноос idx-ээр root хийсэн дэд модны  Tree-ийн өндрийг буцаана */
int height(struct Tree *p, int idx)
{
	/* Энд өндрийг олох үйлдлийг хийнэ */
}

/* p-ийн зааж буй Tree-д x утгыг оруулна */
void add(struct Tree *p, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	p->dat[p->size] = x;
	p->size++;
}

/* p-ийн зааж буй Tree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно */
void leaves(struct Tree *p, int idx)
{
	/* Энд навчуудыг үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx зангилаанаас доошхи бүх үр садыг хэвлэнэ  */
void descendants(struct Tree *p, int idx)
{
	/* Энд үр садыг олох үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ */
void ancestors(struct Tree *p, int idx)
{
	/* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилааны ах, дүүгийн зангилааны дугаарыг буцаана
   (Нэг эцэгтэй зангилаа). Байхгүй бол -1-г буцаана
 */
int sibling(struct Tree *p, int idx)
{
	/* Энд ах, дүүг олох үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилааны хүүхдүүдийн утгыг хэвлэ.
 */
void children(struct Tree *p, int idx)
{
	/* Энд хүүхдүүдийн утгыг хэвлэх үйлдлийг хийнэ үү */
}
/* p-ийн зааж буй Tree-д idx дугаартай зангилааны эцгийн утгыг хэвлэ.
 */
void parent(struct Tree *p, int idx)
{
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ */
void preorder(struct Tree *p, int idx)
{
	/* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
	if (idx < p->size)
	{
		printf("%d\n", p->dat[idx]);
		preorder(p, 2 * idx + 1);
		preorder(p, 2 + idx + 2);
	}
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ */
void inorder(struct Tree *p, int idx)
{
	/* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ */
void postorder(struct Tree *p, int idx)
{
	/* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Tree-д idx дугаартай зангилаанаас үндэс хүртэлх оройнуудын тоог буцаана.
   x тоо олдохгүй бол -1-г буцаана.
 */
int level(struct Tree *p, int idx)
{
}
#endif
