#include <queue>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//struct fruit
//{
//    string name;
//    int price;
//    friend bool operator < (fruit f1, fruit f2)
//    {
//        return f1.price > f2.price;  //价格低优先级高
//    }
//}f1,f2,f3;

//int main()
//{
////    priority_queue<int> q;
////    q.push(3);
////    q.push(4);
////    q.push(1);
////    printf("size = %d\n", q.size());
////    printf("%d\n", q.top());
////    q.pop();
////    printf("%d\n", q.top());

//    priority_queue<int, vector<int>, greater<int> > q2;
//    q2.push(3);
//    q2.push(4);
//    q2.push(1);
//    printf("%d\n",q2.top());

//    priority_queue<fruit> q;
//    f1.name = "peach";
//    f1.price = 3;
//    f2.name ="pear";
//    f2.price = 4;
//    f3.name = "apple";
//    f3.price = 1;
//    q.push(f1);
//    q.push(f2);
//    q.push(f3);
//    cout<<q.top().name<<" "<<q.top().price<<endl;
//    return 0;
//}

struct fruit
{
    string name;
    int price;
}f1,f2,f3;

struct cmp
{
    bool operator () (fruit f1, fruit f2)
    {
        return f1.price > f2.price;
    }
};

int main()
{
    priority_queue<fruit, vector<fruit>,cmp> q;
    f1.name = "peach";
    f1.price = 3;
    f2.name ="pear";
    f2.price = 4;
    f3.name = "apple";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout<<q.top().name<<" "<<q.top().price<<endl;
    return 0;
}
