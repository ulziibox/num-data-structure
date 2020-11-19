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
/* s Stackiig hooson esehiig shalgah. hooson bol 1-iig, hooson bish bolл 0-iig butsaana */
int empty(struct Stack *s)
{
	if (s->top == NULL)
		return 1;
	return 0;
}

/* s Stackd x utgiig nemeh */
void push(struct Stack *s, int x)
{
	struct Node
}

/* s Stackees element utgah, ustaj bui elementiin utgiig butsaah */
int pop(struct Stack *s)
{
}

/* s Stackiin oroi elementiin utgiig butsaahнэ */
int top(struct Stack *s)
{
}

/* s Stack niit heden elementteig tootsoolon butsaah */
int size(struct Stack *s)
{
}
/* s Stackiin bukh elementiin utgiig hevleh */
void printStack(Stack *s)
{
}
/* q-ийн зааж буй Stack-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct List *p, int x)
{
}

#endif
