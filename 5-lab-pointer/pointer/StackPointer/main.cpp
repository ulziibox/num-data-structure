
#include <stdio.h>
#include "Stack.h"
int main()
{
	/* Queue үүсгэн, эхлүүлэх */
	struct Stack st;
	init(&st);
	int t, x, pos;

	while (1)
	{
		printf("1: push, 2: pop, 3: size, 4: empty, 5: top, 6: print, 7: search\n");
		scanf("%d", &t);
		error = 0;

		switch (t)
		{
		case 1:
			printf("oruulah utga = ");
			scanf("%d", &x);
			push(&st, x);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga orloo\n", x);
			break;
		case 2:
			x = pop(&st);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga garlaa\n", x);
			break;
		case 3:
		{
			int c = size(&st);
			printf("stackd niit %d element bna\n", c);
			break;
		}
		case 4:
			if (empty(&st))
				printf("Queue xooson\n");
			else
				printf("Queue xooson bish\n");
			break;
		case 5:
			x = top(&st);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin exend bna\n", x);
			break;
		case 6:

			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printStack(&st);
			break;
		case 7:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				printf("%d utga %d bairlald oldloo\n", x, pos);
			break;
		default:
			exit(0);
		}
	}
	/* Queue-ийн эзэмшсэн нөөцийг чөлөөлөх */
	release(&st);
	return 0;
}
