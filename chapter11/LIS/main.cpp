#include <iostream>
#include <cstdio> 

using namespace std;

const int maxn =1000;
int A[maxn], dp[maxn];

int main() 
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
	}
	int ans = -1;
	for(int i=1;i<=n;i++)
	{
		dp[i] = 1;
		for(int j =1; j<i;j++)
		{
			if((A[j]<=A[i])&&(dp[j]+1 >dp[i])) 
			{
				dp[i] = dp[j] +1; 
			}
		} //完成了以A[i]结尾的求lIS长度 
		ans = max(ans, dp[i]);  //每个A[i]中取最大的 
	}
	printf("%d", ans);
	return 0; 
}
