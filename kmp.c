
#include "stdio.h"
#include "string.h"
#include "malloc.h"


char *calcPatt(char *pcPatt, int ilen)
{
    int i=0;
    int j=0;
    char *pclps = 0;

    pclps = malloc(sizeof(char) * ilen);
    if (0 == pclps)
    {
        return pclps;
    }

    for(i = 1; i < ilen;)
    {
        if (pcPatt[i] == pcPatt[j])
        {
            pclps[j] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pclps[j-1];
            }
            else
            {
                pclps[i] = 0;
                i++;
            }
        }
    }

    return pclps;
}


int main()
{
    char text[] = "1b1bbb1aba111";
    char patt[] = "aba";
    char *pclps = 0;
    int i=0, j=0;
    
    pclps = calcPatt(patt, strlen(patt));
    if (0 == pclps)
    {
        return 0;
    }

    while(i < strlen(text) && j < strlen(patt))
    {
        if (text[i] == patt[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
               j = pclps[j-1]; 
            }
            else
            {
                i++;
            }
        }

        if (j == strlen(patt))
        {
            printf("Find KMP %d %d %d\r\n",i,j,i-j);
            break;
        }
    }

    free(pclps);

    return 0;
}