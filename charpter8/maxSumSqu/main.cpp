#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000;
int n, k, x, maxSumSqu = -1, A[maxn]; //����A�е�n����ѡ��k����ʹ�ú�Ϊx, ���ƽ����ΪmaxSumSqu

vector<int> temp, ans; //temp ��ʱ������ ansƽ�������

void DFS(int index, int nowK, int sum, int sumSqu)
{
    if(nowK ==k && sum == x)  //���� ����
    {
        if(sumSqu > maxSumSqu)
        {
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    //�Ѿ�������
    if(index == n || nowK > k|| sum > x) return;
    //ѡ��index����
    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum + A[index], sumSqu + A[index]*A[index]);

    //��ѡindex����
    temp.pop_back();
    DFS(index+1, nowK, sum, sumSqu);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
