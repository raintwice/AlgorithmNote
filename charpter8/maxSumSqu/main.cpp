#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10000;
int n, k, x, maxSumSqu = -1, A[maxn]; //序列A中的n个数选择k个数使得和为x, 最大平方和为maxSumSqu

vector<int> temp, ans; //temp 临时方案， ans平方和最大

void DFS(int index, int nowK, int sum, int sumSqu)
{
    if(nowK ==k && sum == x)  //满足 返回
    {
        if(sumSqu > maxSumSqu)
        {
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    //已经处理完
    if(index == n || nowK > k|| sum > x) return;
    //选择index号数
    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum + A[index], sumSqu + A[index]*A[index]);

    //不选index号数
    temp.pop_back();
    DFS(index+1, nowK, sum, sumSqu);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
