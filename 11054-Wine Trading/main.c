#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long Npeeps,Nmove,i,moving;
    long long *WineQuant;
    while(scanf("%lld",&Npeeps)==1)
          {
            Nmove=0;
            moving=0;
            if (Npeeps==0)break;
            WineQuant = (long long *)malloc(Npeeps*sizeof(*WineQuant));
            /* We get the quantity */
            for(i=0;i<Npeeps;i++)
            {
                scanf("%lld",&WineQuant[i]);
            }
            for (i=1; i<Npeeps;i++)
            {
                moving=WineQuant[i-1];
                WineQuant[i]+=WineQuant[i-1];
                /*we make sure the result is >0 */
                if (moving<0) moving = moving*(-1);
                /*we increase Nmove each time we do a substraction*/
                Nmove+=moving;
            }
            printf("\n%lld",Nmove);
          }
    return 0;
}

