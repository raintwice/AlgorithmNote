#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    for(int i=1;i<=5;i++)
    {
        vi.push_back(i);
    }
    vector<int>::iterator it = vi.begin();
    for(;it!=vi.end();it++)
    {
        printf("%d", *it);
    }
    printf("\n");
    it = vi.begin();
    for(int i=0;i<vi.size();i++)
    {
        printf("%d", *(it + i));
    }
    it = vi.begin();
    printf("\n");
    for(int i=0;i<vi.size();i++)
    {
        printf("%d", vi[i]);
    }
    vi.insert(vi.begin()+2, -1);
    it = vi.begin();
    printf("\n");
    for(int i=0;i<vi.size();i++)
    {
        printf("%d", vi[i]);
    }
    vi.erase(vi.begin()+3);
    printf("\n");
    for(int i=0;i<vi.size();i++)
    {
        printf("%d", vi[i]);
    }
    vi.erase(vi.begin(), vi.begin() + 3);
    printf("\n");
    for(int i=0;i<vi.size();i++)
    {
        printf("%d", vi[i]);
    }
    return 0;
}
