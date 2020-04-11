//
//  single_link_list.c
//  data_structure
//
//  Created by 程威 on 2020/4/11.
//  Copyright © 2020 程威. All rights reserved.
//

#include "single_link_list.h"

void CreateList_L(LinkList linklist,int n)
{   //逆位输入n个元素的值，简历带表头节点的单链线性表L.
    linklist = (LinkList)malloc(sizeof(LNode));
    linklist->next = NULL; // 建立一个带头结点的单链表，
    int i;
    LinkList p;
    for(i = n;i > 0;--i )
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next = linklist->next;
        linklist->next = p; // 插入到表头
    }
}
void CreateList_L__syn(LinkList linklist,int n)
{
    linklist = (LinkList)malloc(sizeof(LNode));
    LinkList pnew,ptail;
    int i;
    linklist->next = NULL;
    ptail = linklist;
    for(i = 0;i < n;i++)
    {
        pnew = (LinkList)malloc(sizeof(LNode));
        printf("请输入第%d个值：",n+1);
        scanf("%d",&pnew->data);
        pnew->next = ptail->next;
        ptail->next = pnew;
        ptail = pnew;
    }

}
Status GetElem_L(LinkList linklist,int i)
{//L 为带头节点的单链表的头指针
    LinkList p;
    p = linklist->next;
    int j = 1;
    while(p&&j < i)
  {
      p = p->next;
      ++j;  }
    printf("第%d个元素的值为：%d\n",i,p->data);
    if(!p||j>i) return ERROR;
    return OK;
}
void OutPut_L(LinkList p)
{
    LinkList temp = p;
    int i = 1;
    while(temp->next)
    {
        temp = temp->next;
        printf("第%d个值为%d\n",i,temp->data);
        i++;
    }
    printf("\n");
}
Status ListInsert_L(LinkList linklist,int i,int e)
{
    LinkList p = linklist;
    int j = 0;
    while(p&&j < i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p||j > i-1) return ERROR;
    LinkList s;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
Status ListDelete_L(LinkList linklist,int i)
{
    LinkList p = linklist;
    int j =  0;
    while(p->next&&j < i-1)
    {
        p = p->next;
        ++j;
    }
    LinkList temp;
    temp = (LinkList)malloc(sizeof(LNode));
    temp = p->next ;
    p->next = temp->next;
    free(temp);
    return OK;
}
void MergeList_L(LinkList source_a,LinkList source_b,LinkList target)
{
    LinkList pa,pb,pc,temp;
    pa = source_a->next;
    pb = source_b->next;
    pc = (LinkList)malloc(sizeof(LinkList));
    pc->next = NULL;//pc作为头节点
    while(pa&&pb)
    {
        temp = (LinkList)malloc(sizeof(LinkList));//将temp作为临时节点
        if(pa->data <= pb->data)
        {
            temp->data = pa->data;
            temp->next = pc->next;
            pc->next = temp;
            pa = pa->next;
        //如果pa.data比pb.data小 则将pa之后的节点链接到pc之后，反之则将pb连接到pc之后
        }
        else
        {
            temp->data = pb->data;
            temp->next = pc->next;
            pc->next = temp;
            pb = pb->next;
        }
    }
    target = pc;
    while(pc->next) //定位pc为尾节点位置
    {
        pc = pc->next;
    }
    pc->next = pa ? pa:pb;
    free(source_b);
}

int test()
{
    int n ;
    int i,value;//插入的位置和值
    int location;//删除的位置
    int location_s;//查找元素的位置
    LinkList p,la,lb,lc;
    printf("请输入链表大小：");
    scanf("%d",&n);
    CreateList_L__syn(p,n);
    OutPut_L(p);
    printf("请输入插入的位置：");
    scanf("%d",&i);
    printf("请输入插入的值：");
    scanf("%d",&value);
    ListInsert_L(p,i,value);
    OutPut_L(p);
    printf("请输入删除的位置：");
    scanf("%d",&location);
    ListDelete_L(p,location);
    OutPut_L(p);
    printf("请输入要查找元素的位置：");
    scanf("%d",&location_s);
    GetElem_L(p,location_s);
    printf("请输入source_a链表大小：");
    scanf("%d",&n);
    CreateList_L(la,n);
    printf("请输入source_b链表大小：");
    scanf("%d",&n);
    CreateList_L(lb,n);
    lc = (LinkList)malloc(sizeof(LinkList));
    MergeList_L(la,lb,lc);
    OutPut_L(lc);
    return 0;
}
