#include <iostream>
#include <cstdio>
#include <algorithm> 

using namespace std;

const int maxn = 10010;
int A[maxn], dp[maxn]; 
bool f[maxn] = {0}; //true��ʾ���ۣ��������� 

//dp[i] ָ��A[i]��β����������к� 

int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	
	//�߽�
	dp[0] = A[0] ;
	for(int i=1;i<n;i++)
	{
		//����dp[i-1],����A[i]��Ӱ��  
		dp[i] = max(dp[i-1]+A[i], A[i]); 
		if(dp[i-1] <0) 
		{
			f[i] = true;   //��¼ÿ�����������еĿ�ʼ 
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
	 int s = 0; //���п�ʼ 
	 for(int i = k;i>=0;i--)
	 {
	 	if(f[i] == true)
		{
			s = i;     //Ѱ�ҿ�ʼͷ 
			break; 
		}
	 }
	 for(int i = s;i<=k;i++)  //������������ 
	 {
	 	printf("%d ", A[i]);
	 }
	 
	 return 0;	
}
