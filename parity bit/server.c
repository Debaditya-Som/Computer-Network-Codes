//server side / reciver
#include<stdio.h>
#include<string.h>
int main()
{
    char str[10];
    printf("Enter data\n");
    fgets(str, sizeof(str), stdin);
    int count = 0, choice;
    printf("1. Even Parity \n2. Odd parity\n");
    scanf("%d",&choice);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='1')
            count++;
    }
    printf("The no of 1s is %d \n",count);
    switch(choice)
    {
        case 1:
                if (count%2==0)
                printf("It is in Even Parity\n");
                else
                printf("Not in Even Parity\n");
                break;
        case 2:
                if (count%2==0)
                printf("It is not in Odd Parity\n");
                else
                printf("In Odd Parity\n");
                break;
    }
}
