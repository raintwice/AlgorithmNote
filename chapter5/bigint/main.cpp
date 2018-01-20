//������ ���� Ĭ��ȫ������ 

#include <iostream>
#include<cstdlib>
#include <string.h> 

using namespace std;

struct bign
{
	int digit[1000];
	int len;
	bign()
	{
		memset(digit, 0 ,sizeof(digit));
		len = 0;
	}
};

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0;i<a.len;i++)
	{
		a.digit[i] = str[a.len-1-i] - '0';
	}
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0; //��λ
	for(int i = 0;i<a.len||i<b.len;i++)
	{
		int temp = a.digit[i] + b.digit[i] + carry;
		c.digit[c.len++] = temp%10;
		carry = temp/10;
	} 
	if(carry != 0)
	{
		c.digit[c.len++] = carry;   //�����λ 
	} 
	return c; 
}

void printbigint(bign a)
{
	for(int i = a.len-1;i>=0;i--)  //�Ӹߵ������ 
	{
		printf("%d", a.digit[i]);
	}
}

//������ 
int compare(bign a, bign b)
{
	if(a.len > b.len ) return 1;
	else if( a.len < b.len ) return -1;
	else
	{
		for(int i = a.len - 1;i>=0;i--)  //һλһλ�Ƚ� 
		{
			if(a.digit[i] > b.digit[i])
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		return 0;  //��� 
	}		
} 

// a > b ���С 
bign sub(bign a, bign b)
{
	bign c;	
	for(int i = 0;i<a.len||i<b.len;i++)
	{
		if(a.digit[i]<b.digit[i])
		{
			a.digit[i+1] -- ;  //��λ 
			a.digit[i]+=10;
		}	
		c.digit[c.len++] = a.digit[i] - b.digit[i]; 
	}
	while(c.len-1 >= 1 &&c.digit[c.len-1] == 0)
	{
		c.len -- ; //ȥ�����λ��0 
	}
	return c;
}

bign multi(bign a, int b)
{
	bign c;
	int carry = 0;
	for(int i = 0;i<a.len;i++)
	{
		int temp = a.digit[i]*b +carry;   
		c.digit[c.len++] = temp %10;  //��λ 
		carry = temp /10;            //�������Ϊ��λ 
	}
	while(carry!=0) //�������Ľ�λ 
	{
		c.digit[c.len++] = carry%10;
		carry /=10;
	}
	return c; 
}

bign divide(bign a, int b, int& r)  //rΪ������Ҳ��������ʱ���м䱻���� 
{
	bign c;
	c.len = a.len;
	for(int i = a.len -1;i>=0;i--)
	{
		r = r*10 + a.digit[i];    
		if(r < b )
		{
			c.digit[i] = 0;
		}		  
		else
		{
			c.digit[i] = r/b;
			r = r%b;
		}
	}
	while( c.len -1 >=1 &&(c.digit[c.len -1 ]==0))
	{
		c.len -- ;    //ȥ����λ��0 
	}
	return c;
}

int main() 
{
//	char str1[1000], str2[1000];
//	scanf("%s%s", str1,str2);
//	bign a = change(str1);
//	bign b = change(str2);
//	printbigint(sub(a,b));

	char str1[1000];
	int n = 0;
	scanf("%s",str1);
	scanf("%d",&n);
	bign a = change(str1);
	int r = 0 ;
	printbigint(divide(a,n,r));
	printf(".......%d",r);
	return 0;
}
