#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, num;
    double MiniDist, dist, TabX[10000], TabY[10000];

    while (scanf("%d", &num))
    {
        if(num == 0)
            break;
        /*initial at the infinity*/
        MiniDist = 100000000;

        for (i = 0; i < num; i++)
        {
            scanf("%lf %lf", &TabX[i], &TabY[i]);
        }
        /*go throught all the point in the tab and compare*/
        for (i = 0; i < num; i++)
        {
            for (j = i + 1; j < num; j++)
            {
                dist = (pow((TabX[j] - TabX[i]),2) + pow((TabY[j] - TabY[i]),2));
                if (MiniDist > dist)
                {
                    MiniDist = dist;
                }
            }
        }
        MiniDist = sqrt(MiniDist);
        if (MiniDist < 10000)
        {
             printf("%.4lf\n", MiniDist);
        }

        else
            printf("INFINITY\n");
    }
    return 0;
}
