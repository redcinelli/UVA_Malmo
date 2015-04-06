#include <stdio.h>
#define min(a,b) (a<b)?a:b
#define max(a,b) (a>b)?a:b
int dpath[12][102];
int dp[12][102];
int map[12][102];
int r,c;
int path(int i,int j)
{
    if(j==c)
        return 0;
    else if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        int m,TheFastest;
        int IsItOkay[3];
        IsItOkay[0]=(i+1)%r;
        IsItOkay[1]=i;
        IsItOkay[2]=(i+r-1)%r;
        TheFastest=IsItOkay[0];
        m = path(IsItOkay[0],j+1);
        if(path(IsItOkay[1],j+1)<m||(path(IsItOkay[1],j+1)==m&&IsItOkay[1]<TheFastest))
        {
            m = path(IsItOkay[1],j+1);
            TheFastest = IsItOkay[1];
        }
        if(path(IsItOkay[2],j+1)<m||(path(IsItOkay[2],j+1)==m&&IsItOkay[2]<TheFastest))
        {
            m = path(IsItOkay[2],j+1);
            TheFastest = IsItOkay[2];
        }
        dpath[i][j+1]=TheFastest;
        return dp[i][j]=map[i][j]+m;
    }
}
int main()
{
    int i,j;
    while(scanf("%d %d",&r,&c)==2)
    {
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                scanf("%d",map[i]+j);
                dp[i][j]=-1;
            }
        int min = path(0,0);
        int TheFastest = 0;
        for(i=1; i<r; i++)
            if(path(i,0)<min)
            {
                TheFastest = i;
                min = path(i,0);
            }
        i = TheFastest;
        for(j=0; j<c-1; j++,i = dpath[i][j])
            printf("%d ",i+1);
        printf("%d\n",i+1);
        printf("%d\n",min);

    }
    return 0;
}
