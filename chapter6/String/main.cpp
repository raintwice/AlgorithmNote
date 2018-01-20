#include <iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
    string str = "abcd";
    cout<<str;
    string str2;
    cout<<"Please input a strings!\n";
    cin>>str2;
    cout<<str2<<endl;
    printf("%s\n",str2.c_str());  //c字符串输出
    for(string::iterator it = str2.begin();it!=str2.end();it++) // 迭代器单个输出
    {
        printf("%c", *it);
    }
    cout<<endl;
    string strnew = str + str2; //operator +
    cout<<strnew<<endl;
    string::iterator it = strnew.begin();
    strnew.erase(it+1, it+3);
    cout<<strnew<<endl;
    return 0;
}
