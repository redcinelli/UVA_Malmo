#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long loop,contrymen,ans,nbbeast,nbm,coef,i,j;
    while(scanf("%lld",&loop)==1)
    {
        for(i=0;i<loop;i++)
        {
            ans=0;
            scanf("%lld",&contrymen);
            for(j=0;j<contrymen;j++)
            {
                scanf("%lld %lld %lld",&nbbeast, &nbm, &coef);
                ans=ans+(nbbeast*coef);
            }
            printf("%lld\n",ans);

        }
    }
    return 0;
}
