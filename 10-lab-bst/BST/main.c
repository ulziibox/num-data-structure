#include <stdio.h>
#include "bst.h"
int main()
{
	/* List үүсгэн, эхлүүлэх */
	struct Node *root, *n;
	int c, x;
	root = NULL;
	while (1)
	{
		printf("\n1: search, 2: insert, 3: remove, 4: print, 5: height, 6: exit\n");

		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			n = find(root, x);
			if (n == NULL)
				printf("%d utga oldsongui\n", x);
			else
				printf("%d utga oldloo\n", x);
			break;
		case 2:
			printf("nemeh toog oruul: ");
			scanf("%d", &x);
			root = insert(root, x);
			break;
		case 3:
			printf("ustgah toog oruul: ");
			scanf("%d", &x);
			root = remove1(root, x);
			break;
		case 4:
			inorder(root);
			break;
		case 5:
			printf("modnii undur = %d", height(root));
			break;
		default:
			exit(0);
		}
	}
	/* List-ийн эзэмшсэн нөөцийг чөлөөлөх */
	delete_tree(root);
	return 0;
}
