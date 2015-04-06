#include <stdio.h>
#include <stdlib.h>

int Yolo(long long i,long long *Mark,long long **tab,long long Cpt,long long Ninha )
{
    int j=0;
    /*printf("2");*/
    for (j=0;j<Ninha;j++)
    {
        /*printf("3");*/
        if((tab[i][j]==1)&&(Mark[j]==0))
        {
            /*printf("4");*/
            Cpt++;
            Mark[j]=1;
            /*printf("5");*/
            Cpt=Yolo(j,Mark,tab,Cpt,Ninha);
        }
    }
    return Cpt;
}

int main()
{
    long long  Ncase=0,n,Ninha=0,Npair=0,i=0,P1,P2,Cpt,Themax,j;
    long long *Mark;
    long long **tab;



    scanf("%lld",&Ncase);

    /*initialization of the variable */
    for(n=0;n<Ncase;n++)
    {
        Themax=0;
        P1=0;
        P2=0;
        Ninha=0;
        Npair=0;
        Cpt=0;

        scanf("%lld %lld",&Ninha,&Npair);
        tab=(long long **)malloc(sizeof(*tab)*Ninha);
        Mark=(long long *)malloc(sizeof(*Mark)*Ninha);
        for(i=0;i<Ninha;i++)
        {
            tab[i]=(long long *)malloc(sizeof(**tab)*Ninha);
        }
        /*make sure all the array are empty */
        for(i=0;i<Ninha;i++)
        {
            for(j=0;j<Ninha;j++)
            {
                tab[i][j]=0;
            }
            Mark[i]=0;
        }
        /*we fill the friend map */
        for (i=0;i<Npair;i++)
        {
            scanf("%lld %lld",&P1,&P2);
            tab[P2-1][P1-1]=1;
            tab[P1-1][P2-1]=1;
        }
        /*
        for(i=0;i<Ninha;i++)
        {
            for(j=0;j<Ninha;j++)
            {
                printf("%lld ",tab[i][j]);
            }
            printf("\n");
        }

        /*we got through the friend map and count hom many friend */
        for (i=0;i<Ninha;i++)
        {
            if (Mark[i]==0)
            {
                Cpt=1;
                /*printf("1");*/
                Mark [i]=1;
                P1=Yolo(i,Mark,tab,Cpt,Ninha);
            }
            if (P1>Themax)Themax=P1;
        }
        printf("\n%lld",Themax);
    }
    return 0;
}




















#include <stdio.h>
#define max(a,b) (a>b)?a:b
int set[30005];
int count[30005];
int getParent(int i,int *set)
{
    if(i==set[i])
        return i;
    else
        return (set[i]=getParent(set[i],set));
}
int isUnion(int a,int b,int* set)
{
    return getParent(a,set)==getParent(b,set);
}
void makeUnion(int a,int b,int* set)
{
    set[getParent(a,set)] = getParent(b,set);
}
int main()
{
    int c,i,k,n,m;
    scanf("%d",&c);
    /*get the number of ine and read them all*/
    while(c--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            count[set[i]=i]=0;
        while(m--)
        {
            scanf("%d %d",&i,&k);
            makeUnion(i,k,set);
        }
        for(k=1;k<=n;k++)
            count[getParent(k,set)]++;
        m=1;
        for(i=1;i<=n;i++)m=max(m,count[i]);
        printf("%d\n",m);
    }
    return 0;
}
*/
