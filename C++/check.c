#include<stdio.h>
#include<string.h>
int checksum(int fl)
{
char in[100];
int i,sum=0,n,temp,temp1;
scanf("%s",in);
if(strlen(in)%2!=0)
        n=(strlen(in)+1)/2;
else
        n=(strlen(in))/2;
for(i=0;i<n;i++)
    {
temp=in[i*2];
temp=(temp*256)+in[(i*2)+1];
sum=sum+temp;
    }
if(fl==1)
    {
printf("Enter the checksum value \n");
scanf ("%x", &temp);
sum+=temp;
    }
if(sum%65536!=0)
    {
        n=sum%65536;
sum=(sum/65536) + n;
    }
sum=65535-sum;
printf("%x\n",sum);
return sum;
}
int main()
{
int ch,sum;
do{
printf("1.Encode \n2.Decode \n3.Exit \n");
scanf("%d",&ch);
switch(ch)
        {

case 1: printf("Enter the string \n");
sum=checksum(0);
printf("Checksum to append is:%x \n",sum);
break;
case 2: printf("Enter the string \n");
sum=checksum(1);
if(sum!=0)
printf("The data has been tampered with or invalid checksum\n");
else
printf("The checksum is valid \n");
break;
case 3: break;
default: printf("Invalid option, try again \n");
        }
    }
while(ch!=3);

return 0;
}

