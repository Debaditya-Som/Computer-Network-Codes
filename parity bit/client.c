//client side code for partiy bit// generaion of data word
#include<stdio.h>
#include<string.h>
int main()
{
    char str[50];
    printf("Enter data\n");
    gets(str);
    int count = 0, choice;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='1')
            count++;
    }
    printf("The no of 1s is %d \n",count);
    char e_dw[strlen(str)+1];
    char o_dw[strlen(str)+1];
    strcpy(e_dw,str);
     strcpy(o_dw,str);
    if (count%2==0)
               { e_dw[strlen(e_dw)] = '0';
                o_dw[strlen(o_dw)] = '1';
               }
    else
                {
                e_dw[strlen(e_dw)] = '1';
                o_dw[strlen(o_dw)] = '0';
            
    }
    printf("Generated even parity : %s\n",e_dw);
    printf("Generated odd parity : %s",o_dw);
    
    
}
