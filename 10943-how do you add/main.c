#include <stdio.h>
#define N 105
unsigned int Tab[N][N];
/*we re using the recurtion*/
unsigned int Yoloo(int n,int k)
{
    /*make sure we don't work for nothing*/
    if(n<0||k<0)
        return 0;
    /*if we already have the result .... don't work for nothing*/
    if(Tab[n][k]!=-1)
        return Tab[n][k];
    else
    {
        int i;
        unsigned int Recur = 0;
        for(i=0;i<=n;i++)
            /*this way we re counting down the possibility by check them*/
            Recur+=(Yoloo(n-i,k-1)%1000000);
        return Tab[n][k]=Recur%1000000;
    }
}
int main()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            Tab[i][j]=-1;
    Tab[0][0]=1;
    while(scanf("%d %d",&i,&j)==2&&i)
        printf("%u\n",Yoloo(i,j));
    return 0;
}
