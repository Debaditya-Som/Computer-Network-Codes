//client side code for checksum
#include<stdio.h>
#include<string.h>
int main()
{
    int carry,tempsum,flase_index,sl;
    char str[50];
    printf("Entr codeword");
    gets(str);
    printf("Segment length: ");
    scanf("%d",&sl);
    char sum[sl];
    for(int i =0;i<sl;i++)
        sum[i]=0;
    int len = strlen(str);
    char data[sl];
    if(len%sl!=0)
    {
        int red = sl-(len%sl);
        for(int i=0;i<red;i++)
        {
            data[i]=0;
        }
        strcat(data,str);
        strcpy(str,data);
        len+=red;
    }
    
    for(int i=len-1;i>=0;i=i-sl)
    {
        carry = 0;
        tempsum=0;
        flase_index=sl-1;
        for(int j=i-sl;j>=0;j--)
        {
            tempsum= sum[j]+ (str[flase_index]-48) + carry;
            sum[flase_index]= tempsum%2;
            carry = tempsum/2;
            flase_index--;
        }
        if(carry==1)
        {
            for(int k=sl-1;k>=0;k--)
            {
                sum[k]= (sum[k]+carry)%2;
                carry = sum[k]/2;
            }
        }
       
    }
     for(int i=0;i<sl;i++)
        {
            if(sum[i]==0)
                sum[i]=1;
            else
                sum[i]=0;
            printf("%d",sum[i]);
            str[i+len]=sum[i]+48;
        }
        printf("\n%s",str);
}
