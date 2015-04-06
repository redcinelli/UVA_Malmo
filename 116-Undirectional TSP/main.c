/*#include <stdio.h>
#include <stdlib.h>
int MyDijsktra(int** TheArray,int** TheShadow,int Col,int nbline,int nbcol)
{
    int Max=10000;
    int i,startLine;
    if(Col=nbcol)
    {

    }
    else
    {


    }
    return 0;
}

int main()
{
    int line,col,i,j;
    int** TheArray;
    int** TheShadow;
    while(scanf("%d",&line)==1)
    {
        scanf("%d",&col);
        TheArray=(int**)malloc(sizeof(int*)*line);
        TheShadow=(int**)malloc(sizeof(int*)*line);
        for(i=0;i<line;i++)
        {
            TheArray[i]=(int*)malloc(sizeof(int)*col);
            TheShadow[i]=(int*)malloc(sizeof(int)*col);
        }
        for(i=0;i<line;i++)
        {
            for(j=0;j<col;j++)
            {
                scanf("%d",&TheArray[i][j]);
                TheShadow[i][j]=0;
            }
        }

        for(i=0;i<nbline;i++)
        {
            if(TheArray[i][Col]<Max)
            {
                MAx=TheArray[i][Col];
                startLine=i;
            }
        }


    }
}
*/
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
        int m,best;
        int valid[3];
        valid[0]=(i+1)%r;
        valid[1]=i;
        valid[2]=(i+r-1)%r;
        best=valid[0];
        m = path(valid[0],j+1);
        if(path(valid[1],j+1)<m||(path(valid[1],j+1)==m&&valid[1]<best))
        {
            m = path(valid[1],j+1);
            best = valid[1];
        }
        if(path(valid[2],j+1)<m||(path(valid[2],j+1)==m&&valid[2]<best))
        {
            m = path(valid[2],j+1);
            best = valid[2];
        }
        dpath[i][j]=best;
        return dp[i][j]=map[i][j]+m;
    }
}
int main()
{
    int i,j;
    while(scanf("%d %d",&r,&c)==2)
    {
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                scanf("%d",map[i]+j);
                dp[i][j]=-1;
            }
        int min = path(0,0);
        int best = 0;
        for(i=1;i<r;i++)
            if(path(i,0)<min)
            {
                best = i;
                min = path(i,0);
            }
        i = best;
        for(j=0;j<c-1;j++,i = dpath[i][j])
            printf("%d ",i+1);
        printf("%d\n",i+1);
        printf("%d\n",min);

    }
    return 0;
}
