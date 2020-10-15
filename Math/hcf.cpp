#include<stdio.h>
int main()
{
    int a=0,b=0,c=1,e=0,m=0,n=0;
    printf("ENTER NUMBER");
    scanf("%d%d%d%d",&a,&b,&m,&n);
    if((a>b)&&(a>m)&&(a>n))
        e=a;
    if((b>a)&&(b>m)&&(b>n)) e=b;
    if((m>a)&&(m>b)&&(m>n)) e=m;
    else e=n;
    for(int i=2;i<=e;i++)
    {
        if((a%i==0)||(b%i==0)||(m%i==0)||(n%i==0))
        {
           while((a%i==0)||(b%i==0)||(m%i==0)||(n%i==0))
           {    if(a%i==0)
               {a=a/i;}
               if(b%i==0)
            {b=b/i;}
            if(m%i==0)
               {m=m/i;}
               if(n%i==0)
               {n=n/i;}

            c=c*i;
            }
            if((a==1)&&(b==1)&&(m==1)&&(n==1))
    break;
        }



}
 printf("%d",c);
return 0;
}
