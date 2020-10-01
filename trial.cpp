#include<bits/stdc++.h>
using namespace std;
int main()
{

    vector <long long int> v;
    v.push_back(9);
    int q=0,s=0;
     for(int j=0;j<10;j++)
     {   q++;
         cout<<9*pow(10,q)<<"\n";
         int g=9*pow(10,q)+0.5;
         v.push_back(g);
          s=v.size();

         for(int i=0;i<s-1;i++)
          {
            v.push_back((9*pow(10,q))+v[i]);
          }
     }
     for(int w=0;w<v.size();w++)
     {
         if(v[w]%412==0)
            {cout<<v[w];
         break;}
     }
     cout<<"size="<<v.size();
}
