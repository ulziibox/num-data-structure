
#include <stdio.h>
#include "Stack.h"
int main()
{
	/* Queue үүсгэн, эхлүүлэх */
	struct Stack st;
	init(&st, 10);
	int t, x;
	while (1)
	{
		printf("1: push, 2: pop, 3: size, 4: empty, 5: top\n");
		scanf("%d", &t);
		error = 0;

		switch (t)
		{
		case 1:
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
			printf("\n%d element baina\n", size(&st));
			break;
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
			print(&st);
			break;
		default:
			exit(0);
		}
	}
	/* Queue-ийн эзэмшсэн нөөцийг чөлөөлөх */
	release(&st);
	return 0;
}
