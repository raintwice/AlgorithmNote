#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
const int maxn = 100;
struct node
{
    int x,y;
    int step;
}S,T,Node;   //S起点，T终点 Node临时

int n, m; //行 列
char maze[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0,0,1,-1};
int Y[4] = {1,-1,0,0};

bool test(int x,int y)  //检测位置是否合法
{
    if(x >= n||x<0||y>=m||y<0)
    {
        return false;
    }
    if(maze[x][y] == '*')
    {
        return false;
    }
    if(inq[x][y] == true)
    {
        return false;
    }
    return true;
}

int BFS()
{
    queue<node> q;
    q.push(S);
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        if(top.x == T.x&&top.y == T.y)  //发现终点
        {
            return top.step;
        }
        for(int i = 0;i<4;i++)   //可达相邻位置入队
        {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(test(newX,newY))
            {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step + 1;
                q.push(Node);
                inq[newX][newY] = true; //已访问
            }
        }
    }
    return -1;  //无法到达
}

int main()
{
    scanf("%d%d", &n,&m);
    for(int i = 0;i<n;i++)
    {
        getchar(); //滤掉换行
        for(int j=0;j<m;j++)
        {
            maze[i][j]=getchar();
        }
        maze[i][m+1] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d\n",BFS());
    return 0;
}
