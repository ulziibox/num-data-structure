
#include <stdio.h>
#include "CompleteTree.h"
int main()
{
	/* List үүсгэн, эхлүүлэх */
	struct Tree st;
	int n=20;
	init(&st, n);
	int t, x, pos;
	int a[20]={	1,
				11,12,
				111,112,121,122,
				1111,1112,1121,1122,1211,1212,1221,1222,
				11111,11112,11121,11122,11211};
	for(int i=0;i<n;i++){
        add(&st,a[i]);
	}
	while (1) {
		printf("1: search, 2: child of, 3: parent of, 4: sibling of"
		       "5: ancestor of, 6: desendant of, 7: level of, 8: height of sub tree, 9: pre order,"
			   "10: post order, 11: in order, 12: leafs, 13: exit\n");
		scanf("%d", &t);
		error = 0;

		switch (t) {
		case 1:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				printf("%d utga %d bairlald oldloo\n", x, pos);
			break;
		case 2:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				parent(&st,pos);
			break;
		case 3:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				children(&st,pos);
			break;
        case 4:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				{
				    int s=sibling(&st,pos);
                    if(s!=-1)
                        printf("%d utgatai zangilaanii ah duu n %d",x,st.dat[s]);
                    else
                        printf("%d utgatai zangilaa ah duugui %d",x);
				}
			break;

        case 5:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				ancestors(&st,pos);
			break;
        case 6:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				descendants(&st,pos);
			break;
        case 7:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				level(&st,pos);
			break;
        case 8:
			printf("Xaix toog oruul: ");
			scanf("%d", &x);
			pos = find(&st, x);
			if (pos == -1)
				printf("%d utga oldsongui\n", x);
			else
				height(&st,pos);
			break;
        case 9:
			preorder(&st,0);
			break;
        case 10:
			postorder(&st,0);
			break;
        case 11:
			inorder(&st,0);
			break;
        case 12:
			leaves(&st,0);
			break;
		default:
			exit(0);
		}
	}
	/* List-ийн эзэмшсэн нөөцийг чөлөөлөх */
	release(&st);
	return 0;
}
