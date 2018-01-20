#include <iostream>
#include <vector>

using namespace std;
const int MAXV = 1000;
const int INF = 1000000;
vector<int> Adj[MAXV];

int n; //¶¥µãÊý
bool vis[MAXV]  = {false};

void DFS(int u, int depth)
{
    vis[u] = true;
    for(int i = 0;i<Adj[u].size();i++)
    {
        if(vis[v] == false)
        {
            DFS(v, depth + 1);
        }
    }
}

int main()
{


    return 0;
}
