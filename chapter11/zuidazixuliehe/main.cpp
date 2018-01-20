#include <iostream>
#include <cstdio>
#include <algorithm> 

using namespace std;

const int maxn = 10010;
int A[maxn], dp[maxn]; 
bool f[maxn] = {0}; //true表示Ａ［ｉ］新起计算 

//dp[i] 指以A[i]结尾的最大子序列和 

int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	
	//边界
	dp[0] = A[0] ;
	for(int i=1;i<n;i++)
	{
		//已求dp[i-1],考虑A[i]的影响  
		dp[i] = max(dp[i-1]+A[i], A[i]); 
		if(dp[i-1] <0) 
		{
			f[i] = true;   //记录每段连续子序列的开始 
		}
		
	}
	int k = 0;
	for(int i=0;i<n;i++)
	{
		if(dp[i]>dp[k])
		{
			k = i;
		}
	 } 
	 printf("%d\n", dp[k]);
	 int s = 0; //序列开始 
	 for(int i = k;i>=0;i--)
	 {
	 	if(f[i] == true)
		{
			s = i;     //寻找开始头 
			break; 
		}
	 }
	 for(int i = s;i<=k;i++)  //输出最大子序列 
	 {
	 	printf("%d ", A[i]);
	 }
	 
	 return 0;	
}
