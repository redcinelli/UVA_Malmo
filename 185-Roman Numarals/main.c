#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Tab[9];
    while(gets(Tab))
    {
        if (Tab[0]=='#')
            break;
        int sum,res,i=0;
        char buffer[9];
        while(Tab[i]!='=')
        {
            while(Tab[i]!='+')
            {
                buffer[b]=Tab[i];
                b++;
            }

        }
    }
}
int GetTheRoman(char Tab[9])
{
    int TheNumber=0;
    for(int i=0;i<9;i++)
    {
        if (Tab[i]=='M') TheNumber+=1000;
        if (Tab[i]=='D'&&Tab[i+1]!='M')TheNumber+=500;
        if (Tab[i]=='C'&&Tab[i+1]!='M')

    }
    return TheNumber;
}
