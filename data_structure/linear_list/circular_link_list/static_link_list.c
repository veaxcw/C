//
//  static_link_list.c
//  data_structure
//
//  Created by 程威 on 2020/4/11.
//  Copyright © 2020 程威. All rights reserved.
//

#include "static_link_list.h"


void Initspace_SL(SLinkList &space)
{
    int i;
    for (i = 0; i < MAXSIZE-1;++i)
    {
    space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
}//初始化
void Creatspace_SL(SLinkList &space)
{
    int i,j;
    printf("输入静态链表大小：");
    scanf("%d",&i);
    for(j = 1; j < i+1;j++)
    {
        space[j].data = (char *)malloc(sizeof(char)*4);
        scanf("%s",space[j].data);//data 为char*，如果是data[],会出现不可预料的错误，瞎国标赋值，以后都用char*,记得初始化。
    }
    space[i].cur = 0;
    space[0].cur = i+1;//有效链表的第一个节点其“指针域”指向备用链表的头节点
}
void Output_SL(SLinkList &space)
{
    int i = 0;
    do
    {
        i++;
        printf("第%d值为：%s\n",i,space[i].data);
    }
    while(space[i].cur);
}
int Malloc_SL(SLinkList &space)
{
    int i;
    i = space[0].cur;
    if(space[0].cur)
    {
        space[0].cur = space[i].cur;
    }
    return i;
}
void Free_SL(SLinkList &space,int k)
{
      space[k].cur = space[0].cur;
      space[0].cur = k;
}
int Insert_SL(SLinkList &space,int k,char *c)
{
    int i = MAXSIZE-1;
    int j;//获取新节点的位置
    //c = (char*)malloc(sizeof(char)*4);
    if(k < 1||k > i )
        return ERROR;
    else
    {
        j = Malloc_SL(space);
        space[j].data = (char*)malloc(sizeof(char)*4);
        strcpy(space[j].data,c);
        space[j].cur = space[k].cur;
        space[k].cur = j;
        return OK;
    }
}
int main()
{
    int location;
    char *value;
    value = (char*)malloc(sizeof(char)*4);
    SLinkList SL;
    Initspace_SL(SL);
    Creatspace_SL(SL);
    printf("请输入插入位置：");
    scanf("%d",&location);
    printf("请输入插入的字符：");
    scanf("%s",value);
    Insert_SL(SL,location,value);
    Output_SL(SL);
    return 0;
}
© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About

