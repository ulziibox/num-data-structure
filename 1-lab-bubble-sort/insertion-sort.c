#include <stdio.h>

int main()
{
    int n, i, j, temp;
    //Husnegtiin elementiin toog garaas avah
    printf("Enter array number: ");
    scanf("%d", &n);

    //Avsan n toonii daguu sanah oigoo beldeh
    int a[n];
    //for davtalt ashiglan husnegtdee utguudiig neg negeer ni oruulah
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    //0 dugeer elementee sorted hesegt oruulsan tul davtaltiin indexee 1-ees ehluulj baigaa
    for (i = 1; i < n; i++)
    {
        //sorted hesgiinhee suuliin elementees ehelj davtalt ehluuleh
        for (j = i; j > 0; j--)
        {
            //j == i buyu unsorted hesgiin ehnii elementiig umnuh elementtei buyu sorted hesgiin suuliin elementees ehelj jishih uildleer shalgaj ehelsen
            //tsaash current elementiig umnuh elementtei ni jisheed yvna
            if (a[j] < a[j - 1])
            {
                //nuhtsul unen buyu current element ni umnuh elementeesee baga baival hoyr elementiin bairiig hoorond ni solih
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            };

            //shalgah uudnees sorted hesgee hevlej uzuuleh
            printf("sorted: %d\n", a[j]);
        };
    };

    //eremblegdsen husnegtiin elementuudiig neg negeer ni hevlej uzuuleh
    printf("sorted: ");
    for (i = 0; i < n; i++)
        printf("[%d]", a[i]);

    return 0;
}