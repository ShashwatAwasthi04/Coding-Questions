#include<iostream>
using namespace std;
int main()
{
    int n,g=0,s=0,l=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
       for(int j=i;j<n;j++)
        {
          for(int k=i;k<j+1;k++)
              {
                  s=s+a[k];
              }
              if(s>g){
                g=s;

              }
               s=0;
        }
       // l=0;
    }
    cout<<"\n"<<g;

}
