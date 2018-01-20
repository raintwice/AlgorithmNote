#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> st;
    st.insert(3);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        printf("%d ", *it);
    }
    printf("\n");
    set<int>::iterator it = st.find(6);
    if(it == st.end())
    {
        printf("Cann't find this value!\n");
    }else
    {
        printf("%d\n", *it);
    }
    st.insert(100);
    st.erase(st.find(3));
    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        printf("%d ", *it);
    }
    printf("\n");
    st.erase(100);
    for(set<int>::iterator it = st.begin();it != st.end();it++)
    {
        printf("%d ", *it);
    }
    printf("\n");
    st.insert(10001);
    printf("%d ", st.size());
    st.clear();
    printf("%d ", st.size());
    return 0;
}
