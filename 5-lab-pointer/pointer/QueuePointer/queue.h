#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Queue
{
	struct Node *head;
	struct Node *tail;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Queue xooson!"};
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
	return q->head == NULL ? 1 : 0;
}
/* q-ийн зааж буй Queue-д x утгыг хийнэ */
void enQueue(struct Queue *q, int x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	//Шинэ node үүсгээд зохих утгыг оноож өгнө
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	new->next = NULL;

	//Хэрвээ Queue хоосон байх тохиолдолд эхлэл, төгсгөл хоёрыг нэг гэж үзнэ
	if (q->head == 0 && q->tail == 0)
		q->head = q->tail = new;
	else
	{
		//Бусад тохиолдолд дарааллын хамгийн сүүлд оруулж, сүүлд оруулсан
		//node оо tail-д оноож өгнө.
		q->tail->next = new;
		q->tail = new;
	}
}

/* q-ийн зааж буй Queue-с гарган буцаана */
int deQueue(struct Queue *q)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	//Хоосон тохиолдолд
	if (q->head == NULL)
		return error = 1;

	//Бусад тохиолдолд
	struct Node *temp = q->head; //Шинэ node үүсгэж эхлэлийг хадгална

	//head буюу эхлэлийн node-д 2 дахь node-г онооно
	//Ингэснээр дараалал 2 дахь node-с эхэлнэ гэсэн үг
	q->head = q->head->next;
	int temp_data = temp->data; //Буцаах утгаа хадгална
	free(temp);					//Санах ойгоо чөлөөлнө
	return temp_data;

	//Асуудал:
	//Дараалалд элемент оруулаад, бүгдийг нь устгасны дараа
	//дахиж шинээр оруулах үед enqueue ажиллахгүй байгааг тодруулах
	//free() ямар утгыг оноодог, Head-дээ NULL утгыг өгсөн нь зөв эсэх.
}

/* q-ийн зааж буй Queue-н утгуудыг хэвлэнэ */
void print(struct Queue *q)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */
	struct Node *index;
	index = q->head;
	printf("\nQueue:\n");

	while (index != NULL)
	{
		printf(" %d |", index->data);
		index = index->next;
	}
	printf("\n");
}

/* q-ийн зааж буй Queue-н хамгийн эхний элементийн утгыг буцаана.
   Гаргах үйлдэл хийхгүй.
 */
int front(struct Queue *q)
{
	if (q->head == NULL)
		return error = 1;
	return q->head->data;
}
/* q-ийн зааж буй Queue-н хамгийн сүүлийн элементийн утгыг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int back(struct Queue *q)
{
	if (q->head == NULL)
		return error = 1;
	return q->tail->data;
}
/* q-ийн зааж буй Queue-д хэдэн элемент байгааг буцаана.
   Queue-д өөрчлөлт оруулахгүй.
 */
int size(struct Queue *q)
{
	struct Node *index = q->head;
	int size = 0;
	//Дараалал дуустал index гүйж size-г нэгээр нэмэгдүүлнэ
	while (index != NULL)
	{
		size++;
		index = index->next; //Дараагийн node рүү шилжих
	}
	return size;
}
/* q-ийн зааж буй queue-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Queue *q, int x)
{
	//Жагсаалт хоосон тохиолдолд
	if (q->head == NULL)
		return error = 1;

	//Бусад тохиолдолд
	struct Node *index = q->head;
	int i = 0;
	while (index != NULL)
	{
		if (index->data == x)
			return i;		 //Утга олдвол i байрлалыг буцаана
		index = index->next; // Үгүй тохиолдолд дараагийн node-рүү шилжинэ
		i++;
	}
	return -1;
}

#endif
