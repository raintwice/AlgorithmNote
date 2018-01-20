//字符串hash
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100;
char S[maxn][5], temp[5];
int hashTable[26*26*26 +10];
int hashFunc(char S[], int len)
{
    int id = 0;
    for(int i = 0;i< len;i++)
    {
        id = id*26 + S[i] - 'A';
    }
    return id;
}
int main()
{
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i = 0;i<n;i++)
    {
        scanf("%s",S[i]);
        int id = hashFunc(S[i],strlen(S[i]));
        hashTable[id]++;
    }
    for(int i = 0;i<m;i++)
    {
        scanf("%s",temp);
        int id =hashFunc(temp,3);
        printf("%d\n",hashTable[id]);
    }
    return 0;
}
