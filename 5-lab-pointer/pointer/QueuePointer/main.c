
#include <stdio.h>
#include "queue.h"
int main()
{
	/* Queue үүсгэн, эхлүүлэх */
	struct Queue st;
	init(&st);
	int t, x;

	while (1) {
		printf("1: enqueue, 2: dequeue, 3: print, 4: empty, 5: front,"
		       "6: back, 7: size, 8: search, 9: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			scanf("%d", &x);
			enQueue(&st, x);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga orloo\n", x);
			break;
		case 2:
			x = deQueue(&st);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga garlaa\n", x);
			break;
		case 3:
			print(&st);
			break;
		case 4:
			if (empty(&st))
				printf("Queue xooson\n");
			else
				printf("Queue xooson bish\n");
			break;
		case 5:
			x = front(&st);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin exend bna\n", x);
			break;
		case 6:
			x = back(&st);
			if (error)
				printf("Aldaa: %s\n", error_msg[error]);
			else
				printf("%d utga xamgiin suuld bna\n", x);
			break;
		case 7:
			x = size(&st);
			printf("Queue-d %d shirxeg element bna\n", x);
			break;
		case 8:
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
