#include <stdio.h>

int main()
{
    int n, i, j, temp;

    printf("Enter array number: ");
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        // //sorted elementee alham alhmaar shalgah
        // printf("\nsorted: ");
        // for (int k = 0; k < n; k++)
        //     printf("[%d]", a[k]);
    }

    printf("\nSorted: ");
    for (i = 0; i < n; i++)
        printf("[%d]", a[i]);

    return 0;
}