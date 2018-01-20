#include <iostream>
#include<cmath>
#include<cstdio>
const int maxn = 100000;
int prime[maxn], pNum = 0; //������¼����
bool p[maxn] = {0};        //�����ж�����FALSEΪ����

void Find_Prime()
{
    for(int i=2; i<maxn;i++)
    {
         if(p[i] == false)  //�������������䱶����������
         {
             prime[pNum++] = i;
             for(int j=i+i;j<maxn;j+=i)
             {
                 p[j] = true;
             }
         }
    }
}

struct factor
{
	int x, cnt; 
}fac[10];

int num = 0;

void checkFac(int n)
{	
	int sqr = (int)sqrt(1.0*n);
//	printf("sqr=%d\n", sqr);
	for(int i = 0;i <pNum &&(prime[i]<= sqr);i++ )
	{
		if(n%prime[i] == 0) 
		{
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n%prime[i] == 0)
			{
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
	}
	if(n!=1) //����һ����sqrt����������� 
	{
		fac[num].x = n;
		fac[num++].cnt = 1; 
	}
		
}

int main() 
{
	Find_Prime();
	
	
	int value = 0;
	scanf("%d",&value);
	if(value == 1)
	{
		printf("1=1");
	}
	else
	{							
		checkFac(value);
		printf("%d=",value);
		for(int i =0;i<num;i++)
		{					
			if(i>0) printf("*");
			printf("%d",fac[i].x);			
			if(fac[i].cnt > 1)
			{
				printf("^%d",fac[i].cnt);
			}
		}		
	}

}
