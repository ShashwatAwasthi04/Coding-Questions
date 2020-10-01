#include<bits/stdc++.h>
using namespace std;
int LCP(string a,string b)
{
	int n=a.length();
	
	int dp[n+1][n+1],i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(i==0||j==0)
			{
			dp[i][j]=0;	
			}
			else if(a[i-1]==b[j-1])
			{
					dp[i][j]=dp[i-1][j-1]+1;	
			}
			else
			{
				
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
			
		}
	}
	
	return dp[n][n];
	
}


int main()
{
		int t;
		cin>>t;
		while(t--)
		{
			string s,s1,b,a;
			fflush(stdin);
			cin>>s;
			a=s;
			reverse(s.begin(),s.end());
			b=s;
			int ans=LCP(a,b);
			cout<<ans<<endl;	
			
		}	
	
	
}
