#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    /*we get the line and look for what is inside .... ' '=0 o=1 in ascci code*/
    char lin[11];
    int i,b=0;
    int bits[10];
    int j=0;
    while(gets(lin))
    {
        for ( j=0; j<11; j++)
        {
            if(lin[j]!='_')
            {
                if(lin[j] == 'o')
                {

                    bits[b]=1;
                    b=b+1;/*go to the next room in the tab*/
                }
                else if (lin[j]==' ')
                {
                    bits[b]=0;
                    b=b+1;
                }
            }
        }
        int sum =0;
        for(i=b-1; i>=0; i--)
        {
            sum+=bits[i]*pow(2,b-1-i);
        }
        printf("%c",sum);
        b=0;
    }
    printf("\n");
    return 0;
}

