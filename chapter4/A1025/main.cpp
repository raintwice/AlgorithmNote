#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student
{
    char id[15];        //学号
    int score;          //分数
    int location_number; //考场号
    int local_rank;     //考场内排名
    int total_rank;     //总排名
}stu[30001];

bool cmp(Student a, Student b)
{
    if(a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return strcmp(a.id, b.id) < 0 ;
    }
}

int main()
{
    int loc_total = 0;  //考场总数
    int loc_cnt = 0;     //考场人数
    int num = 0;    //考生总数
    scanf("%d",&loc_total);  //读取考场总数
    int i = 0;
    for(;i<loc_total;i++)
    {
        scanf("%d",&loc_cnt); //读取考场人数
        int j = 0;
        for(;j<loc_cnt;j++)
        {
            scanf("%s",stu[num + j].id);
            scanf("%d",&stu[num + j].score);
            stu[num + j].location_number = i+1; //考场号
        }
        sort(stu + num , stu+num+loc_cnt, cmp);//考场内排序
        stu[num].local_rank = 1;
        for(j=num+1;j<num+loc_cnt;j++)
        {
            if(stu[j].score == stu[j-1].score) //同分同排名
            {
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else
            {
                stu[j].local_rank = j - num + 1;
            }
        }
        num += loc_cnt; //总人数加上当前考场人数
    }
    printf("%d\n",num);
    sort(stu, stu+num, cmp);
    int j = 0;
    stu[j].total_rank = 1;
    printf("%s %d %d %d\n",stu[j].id, stu[j].total_rank,stu[j].location_number,stu[j].local_rank);
    for(j=1;j<num;j++)
    {
        if(stu[j].score == stu[j-1].score) //同分同排名
        {
            stu[j].total_rank = stu[j-1].total_rank;
        }
        else
        {
            stu[j].total_rank = j + 1;
        }
        printf("%s %d %d %d\n",stu[j].id, stu[j].total_rank,stu[j].location_number,stu[j].local_rank);
    }

    return 0;
}
