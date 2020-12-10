#include <stdio.h>
#include "list.h"
int main()
{
	/* List үүсгэн, эхлүүлэх */
	struct List st;
	init(&st, 10);
	int t, x, pos;

	while (1)
	{
		printf(" 1: insert, 2: remove,  3: empty, 5: search, 6: print,"
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
			x = removes(&st, pos);
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
		case 5:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
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
