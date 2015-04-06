#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
    int x, y;

}t_Coord;


int main()
{

    int C,N; /* Number of case & number of LimMountains by case*/
    int i,j; /* Counter*/
    int SunIsShiniing = 0;
    double MeterSun = 0;

    scanf("%d", &C);
    while(C--)
    {
        scanf("%d",&N);
        t_Coord LimMountain[N];

        for(i = 0; i < N; i++)
        {
            scanf("%d %d", &LimMountain[i].x, &LimMountain[i].y);
        }

        /* We sort the array Big X first */
        for(i = N - 2; i >= 0; i--)
        {
            for(j = 0; j<(i+1); j++)
            {
                if(LimMountain[j + 1].x > LimMountain[j].x)
                {
                    t_Coord Buffer = LimMountain[j + 1];
                    LimMountain[j + 1] = LimMountain[j];
                    LimMountain[j] = Buffer;
                }
            }
        }
        for(i = 1; i < N; i++)
        {
            if(LimMountain[i].y > SunIsShiniing)
            {
                /* each time the sun can shine on the mountain we get in and calculated how many meter more */
                double x, y;
                x = LimMountain[i].x - (double)(LimMountain[i].x-LimMountain[i-1].x)*(LimMountain[i].y-SunIsShiniing)/(LimMountain[i].y-LimMountain[i-1].y);
                y = SunIsShiniing;
                MeterSun += sqrt((x-LimMountain[i].x)*(x-LimMountain[i].x) + (y-LimMountain[i].y)*(y-LimMountain[i].y));
                SunIsShiniing = LimMountain[i].y; /* We MAJ the new maxi high of the shadow  */
            }
        }
        printf("%.2lf\n", MeterSun);
    }
    return 0;
}
