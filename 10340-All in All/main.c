#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char Tab[100000],Taba[100000],Tabb[100000];
    int sizeTab,i,j,yoloswaag;
    int coded;
    while(gets(Tab))
    {
        j=0;
        sizeTab=strlen(Tab);
        /*we split the 2 words*/
        for(i=0;i<sizeTab;i++)
        {
            if (Tab[i]==' ')break;
            else Taba[i] = Tab[i];

        }
        i++;
        for(i;i<sizeTab;i++)
        {
            Tabb[j] = Tab[i];
            j++;
        }
        yoloswaag=strlen(Taba);
        /*
        for(i=0;i<strlen(Taba);i++)
        {
            printf("%c",Taba[i]);
        }
        printf("\n");
        for(i=0;i<strlen(Tabb);i++)
        {
            printf("%c",Tabb[i]);
        }

        printf("%d %d",strlen(Taba),strlen(Tabb));*/
        if(!(strlen(Taba)==strlen(Tabb)))
        {
            sizeTab=strlen(Tabb);
            j=0;
            for(i=0;i<sizeTab;i++)
            {
                /*we do the comparison and count hom many they have in common*/
                if(Taba[j]==Tabb[i])
                {

                    j++;
                }

            }
            if(j==yoloswaag)coded=1;
            else coded=0;
        }
        else
        {
            coded=0;
        }
        if (coded)printf("Yes\n");
        else printf("No\n");
        yoloswaag=strlen(Tab);
        /*we empty all the tab*/
        for (i=0;i<yoloswaag;i++)
        {
            Tab[i]=Tabb[i]=Taba[i]='\0';
        }
    }
    return 0;
}


