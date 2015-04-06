#include <stdio.h>
#include <stdlib.h>

int main()
{
    int set=1,nbcol=0,i=0,nbblock=0,nbmax=0,move=0;
    int tab[6];
    while(scanf("%d",&nbcol)==1&&nbcol!=0)
    {
        for(i=0; i<nbcol; i++)
        {
            /*we get all the heigth of each col*/
            scanf("%d",&tab[i]);
            nbblock = nbblock+tab[i];
        }
        /*we find the medium*/
        nbmax=nbblock/nbcol;
        /*and count only the one type ... the one where you have too many or the one you need some*/
        for(i=0; i<nbcol; i++)
        {
            if(tab[i]>nbmax) move=move+(tab[i]-nbmax);
        }
        printf("set #%d\nThe minimum number of moves is %d.",&set,&move);
        set++;
    }
    return 0;
}



