#include <stdio.h>
#include <stdlib.h>
long long yolo(int B,int P,int M)
{
    if(P==0)return 1;
    if (P%2==0)return (yolo(B,P/2,M)*yolo(B,P/2,M))%M;
    else return (yolo(B,(P-1),M)*(B%M))%M;
}
int main()
{
    int R,B,P,M;
    while(scanf("%d %d %d",&B,&P,&M)==3)
    {
        R=yolo(B,P,M);
        printf("%d\n",R);
    }


    return 0;
}

