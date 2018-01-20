#include <iostream>
#include <algorithm>

using namespace std;

const int MAXV = 1000;
const int INF = 100000000;

int n, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s)
{
    //fill(d, d + MAXV, INF);
    //最短路长初始化
    for(int i = 0;i<n;i++)
    {
        d[i] = G[s][i];
    }
    d[s] = 0;
    for(int i = 0;i<n;i++)
    {
        int u = -1, MIN = INF;
        for(int j = 0;j<n;i++)  //找未访问中的顶点中最小的
        {
            if(vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1)  //已经找完了
            return ;
        vis[u] = true;
        for(int v = 0;v<n;v++)  //更新没选中的最短路劲
        {
            if(vis[v] == false &&G[u][v]!=INF && d[v]> (d[u] + G[u][v] ))
            {
                d[v] = d[u] + G[u][v];  //更新最短
            }
        }

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
