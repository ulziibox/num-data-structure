#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Stack
{
	struct Node *top;
};
int error = 0;
const char error_msg[][50] = {
	"",
	"Stack xooson!"};
void init(struct Stack *s)
{
	s->top = NULL;
}
void release(struct Stack *s)
{
	free(s->top);
	free(s);
}
/* s Stackiig hooson esehiig shalgah. hooson bol 1-iig, hooson bish bol 0-iig butsaana */
int empty(struct Stack *s)
{
	if (s->top == NULL)
		return 1;
	return 0;
}

/* s Stackd x utgiig nemeh */
void push(struct Stack *s, int x)
{
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	//Стак хоосон тохиолдолд
	if (s->top == NULL)
	{
		//Эхний node өөрөө сүүлийн node тул next дээр null утгыг хадгалсан
		new->next = NULL;
		//Мөн топ мөн
		s->top = new;
	}
	else
	{
		//Бусад тохиолдолд
		//Шинэ node өмнөх элементүүдийнхээ top нь болж өгөх ёстой
		new->next = s->top;
		s->top = new; //Бас хамгийн сүүлд орж буй учир өөрөө top болох ёстой
	}
}

/* s Stackees element ustgah, ustaj bui elementiin utgiig butsaah */
int pop(struct Stack *s)
{
	//Node-н хаягийг явуулж хоосон эсэхийг шалгана
	if (empty(&s) == 1)
		return error = 1;

	//Бусад тохиолдолд хамгийн дээр байгаа элементийг чөлөөлнө
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	//Санах ойгоос чөлөөлөх болон ямар утга устгаж буйгаа
	//буцаах учир temp гэсэн node-д устгах гэж байгаа node-оо хадгална
	temp = s->top;
	int temp_data = temp->data;
	s->top = s->top->next; //Дараагийн Node-г top node болгох үйлдэл
	free(temp);			   //Санах ойгоос чөлөөлнө
	return temp_data;
}

/* s Stackiin oroi elementiin utgiig butsaahнэ */
int top(struct Stack *s)
{
	return s->top->data;
}

/* s Stack niit heden elementteig tootsoolon butsaah */
int size(struct Stack *s)
{
	struct Node *index = s->top;
	int size = 0;
	//Дараалал дуустал index гүйж size-г нэгээр нэмэгдүүлнэ
	while (index != NULL)
	{
		size++;
		index = index->next; //Дараагийн node рүү шилжих
	}
	return size;
}
/* s Stackiin bukh elementiin utgiig hevleh */
void printStack(struct Stack *s)
{
	if (s->top == NULL)
		error = 1;
	else
	{
		struct Node *index;
		index = s->top;
		do
		{
			printf("%d\n", index->data);
			index = index->next;
		} while (index != NULL);
		printf("\n");
	}
}
/* q-ийн зааж буй Stack-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct Stack *s, int x)
{
	//Жагсаалт хоосон тохиолдолд
	if (s->top == NULL)
		return -1;

	//Бусад тохиолдолд
	struct Node *index = s->top;
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
