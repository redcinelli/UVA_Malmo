#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x[2000];
    int y[2000];
    int n;
    int pos, neg;
    int i, res;

    while (scanf("%d", &n) == 1 && n > 0)
    {
        pos=0;
        neg=0;
        res=0;

        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        x[n] = x[0];
        y[n] = y[0];

        x[n + 1] = x[1];
        y[n + 1] = y[1];

        /*we go through all the point we have and to the covex hull*/
        for (i=0; i<n; i++)
        {
            res = (x[i + 1] - x[i]) * (y[i + 2] - y[i]) - (x[i + 2] - x[i]) * (y[i + 1] - y[i]);
            if (res > 0)
            {
                pos++;
            }

            else if (res < 0)
            {
                neg++;
            }
        }

        if (pos == 0 || neg == 0)
        {
            printf("No\n");
        }
        else printf("Yes\n");
    }
    return 0;
}
