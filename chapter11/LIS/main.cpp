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
		} //�������A[i]��β����lIS���� 
		ans = max(ans, dp[i]);  //ÿ��A[i]��ȡ���� 
	}
	printf("%d", ans);
	return 0; 
}
