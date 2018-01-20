#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include<string>

using namespace std;

struct node
{
    double num; //操作数
    char op;    //操作符
    bool flag;  //true 操作数， false 操作符
};

string str;
stack<node> s;
queue<node> q;
map<char,int> op;

void change()
{
    double num;
    node temp;
    for(int i=0;i<str.length();)
    {
        if(str[i]>= '0'&&str[i]<='9')  //假如是数字
        {
             temp.flag = true; //操作数
             temp.num = str[i++] - '0';
             while(i<str.length()&&(str[i]>= '0'&&str[i]<='9'))
             {
                 temp.num = temp.num * 10 + (str[i]-'0');
                 i++;
             }
             q.push(temp);
        }
        else
        {
            temp.op = str[i];
            temp.flag = false;  //操作符
            //比较栈内操作符与当前操作符优先级
            //当前小于或等于， 操作符栈退栈，入队
            while((!s.empty())&&(op[temp.op] <= op[s.top().op] ))
            {
                q.push(s.top());
                s.pop();                
            }
            s.push(temp);
            i++;
        }
    }
    //将非空栈的操作符弹出
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

double Cal()
{
    double temp1, temp2;
    node cur, temp;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        if(cur.flag == true) s.push(cur); //如果是操作数，进栈
        else  //操作符
        {
            temp2 = s.top().num; //第二操作数
            s.pop();
            temp1 = s.top().num; //第二操作数
            s.pop();
            temp.flag = true;
            switch(cur.op)
            {
                case '+':
                {
                    temp.num = temp1 + temp2;
                    break;
                }
                case '-':
                {
                     temp.num = temp1 - temp2;
                    break;
                }
                case '*':
                {
                    temp.num = temp1 * temp2;
                    break;
                }
                default:
                {
                    temp.num = temp1 / temp2;
                    break;
                }
            }
            s.push(temp);
        }
    }
    return s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin,str),str!="0")
    {
        for(string::iterator it = str.end();it!=str.begin();it--)
        {
            if(*it ==' ')
                str.erase(it); //去除空格
        }
        while(!s.empty())
        {
            s.pop();
        }
        change();
        printf("%.2f\n", Cal());
    }
    return 0;
}
