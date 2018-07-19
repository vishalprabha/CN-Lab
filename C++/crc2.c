#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N strlen(g)

char t[28],cs[28],g[16];
int a,e,c,d,k;

void xor(){
    for(c = 1;c < N; c++)
    cs[c] = (( cs[c] == g[c])?'0':'1');
}

void crc(){
    for(e=0;e<N;e++)
        cs[e]=t[e];
    do{
        if(cs[0]=='1')
            xor();
        for(c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=t[e++];
     }while(e<=a+N-1);
}

int main()
{
    printf("\nEnter data : ");
    scanf("%s",t);
    printf("\n----------------------------------------");
    printf("\nEnter divisor: ");
    scanf("%s", g);
    a = strlen(t);
    for(e=a;e<a+N-1;e++)
        t[e]='0';
    printf("\n----------------------------------------");
    printf("\nModified data is : %s",t);
    printf("\n----------------------------------------");
    crc();
    printf("\nChecksum is : %s",cs);
    for(e=a;e<a+N-1;e++)
        t[e]=cs[e-a];
    printf("\n----------------------------------------");
    printf("\nFinal codeword is : %s",t);
    printf("\n----------------------------------------");
    printf("\nTest error detection 0(yes) 1(no)? : ");
    scanf("%d",&e);

    if(e==0)
    {
    printf("\nEnter no. of errors to be introduced during transmission :");
    scanf("%d",&d);
    srand(time(0));
    for(int j=0;j<d;j++)
    {
        k=rand()%strlen(t)-1;
        if(t[k]=='0')
            t[k]='1';
        else
            t[k]='0';
    }
    printf("\nErroneous data : %s\n",t);
    }
    crc();
    for(e=0;(e<N-1) && (cs[e]!='1');e++)
     ;
        if(e<N-1)
            printf("\nError detected, syndrome bits are: %s\n\n", cs);
        else
            printf("\nNo error detected, syndrome bits are: %s\n\n", cs);
            printf("\n----------------------------------------\n");
        return 0;
}
