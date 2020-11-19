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
        //n - i - 1 ni array iin suuliin elementiig sorted gej uzen, ehnii hesgiig unsorted gj ylgaad unsorted heseg deer davtalt guilgej baigaa
        for (j = 0; j < n - i - 1; j++)

            //current element ni baruun hursh elementeesee ih baival swap hiij baigaa
            if (a[j] > a[j + 1])
            {
                //bairiig ni solih hiih uildel
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
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